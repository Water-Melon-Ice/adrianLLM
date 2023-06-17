import argparse
import requests
import time
from urllib.parse import urlparse
import os

from bs4 import BeautifulSoup

chars = ".-_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

def isDomain(url, url2):
    domain = urlparse(url).netloc
    domain2 = urlparse(url2).netloc
    return domain in domain2 or domain2 == ""

def hasDomain(url2):
    domain2 = urlparse(url2).netloc
    return domain2 != ""

def isPath(url, url2):
    path = urlparse(url).path
    path2 = urlparse(url2).path
    return path in path2

def fixScheme(url):
    if not url.startswith("http"):
        url = "http://" + url
    
    url = url.rstrip()
    return url

def getPage(url):

    url = fixScheme(url)
    page = requests.get(url)
    soup = BeautifulSoup(page.content, 'html.parser')
    return soup

def getLinks(page):
    links = []
    for link in page.find_all('a'):
        if link.get('href') != None:
            links.append(link.get('href'))
    return links

if (__name__ == "__main__"):
    argParser = argparse.ArgumentParser()
    
    argParser.add_argument('outputfile')
    argParser.add_argument('-d', '--delay', type=int, default=10)
    # argParser.add_argument('-t', '--threads', type=int, default='1')
    argParser.add_argument('-p', '--page')
    argParser.add_argument('-s', '--start')

    args = argParser.parse_args()

    output = open(args.outputfile, mode='w+')

    argpage = fixScheme(args.page)

    currlink = fixScheme(args.start)

    output.write(currlink)
    output.write("\n")
    output.flush()

    while currlink !=  None:
        netloc = urlparse(currlink).netloc

        page = getPage(currlink)

        for link in getLinks(page):

            if not isDomain(argpage, link) or not isPath(argpage, link):
                continue

            if not hasDomain(link):
                if isPath(argpage, link):
                    link = fixScheme(netloc + link)
                else:
                    continue


            outputcheck = open(args.outputfile, mode='r+')
            for line in outputcheck:
                if link.strip() == line.strip():
                    break
            else:
                outputcheck.seek(0, os.SEEK_END)
                outputcheck.write(link)
                outputcheck.write("\n")
                outputcheck.flush()
            outputcheck.close()

        time.sleep(args.delay)
        currlink = next(output).strip()
import argparse
import requests
import time
from urllib.parse import urlparse
import os

chars = ".-_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

def makeFilename(url):
    domain = urlparse(url).netloc
    path = urlparse(url).path
    file = domain + "".join(x for x in path if x in chars)
    return file

def fixScheme(url):
    if not url.startswith("http"):
        url = "http://" + url
    
    url = url.rstrip()
    return url

def getPage(url, out):
    
    filename = makeFilename(url)
    output = open(out + filename + ".html", mode='w', encoding="utf-8")

    url = fixScheme(url)

    print(url)
    page = requests.get(url)

    output.write(page.text)

if (__name__ == "__main__"):
    argParser = argparse.ArgumentParser()
    
    argParser.add_argument('outputfolder')
    argParser.add_argument('-d', '--delay', type=int, default=5)
    # argParser.add_argument('-t', '--threads', type=int, default='1')
    group = argParser.add_mutually_exclusive_group(required=True)
    group.add_argument('-i', '--inputs', nargs='+')     #list of paths
    group.add_argument('-f', '--inputfile', type=open)  #file with a list of paths

    args = argParser.parse_args()

    if not os.path.exists(args.outputfolder):
        os.makedirs(args.outputfolder)

    f = args.inputfile
    if(f != None):
        for line in f:
            line.rstrip()
            getPage(line, args.outputfolder)
            if(args.delay != None):
                time.sleep(args.delay)
    else:
        inputs = args.inputs
        for i in inputs:
            getPage(i, args.outputfolder)
            if(args.delay != None):
                time.sleep(args.delay)
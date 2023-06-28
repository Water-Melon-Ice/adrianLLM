import argparse
import os
from bs4 import BeautifulSoup
import sys


def extract(source, destination, tags, attrs):
    file = open(source, encoding="utf-8")
    lines = file.read()
    soup = BeautifulSoup(lines, 'html.parser')
    for tag in tags:
        for element in soup.find_all(tag, attrs):
            if(element.string == None):
                continue
            destination.write((element.get_text(strip=True) + "\n").encode().decode('ascii', 'ignore'))


if (__name__ == "__main__"):
    argParser = argparse.ArgumentParser()
    
    argParser.add_argument('outputfile')
    # argParser.add_argument('-t', '--threads', type=int, default='1')
    argParser.add_argument('-e', '--elements', nargs='+', required=True)
    argParser.add_argument('-a', '--attributes', nargs='*')
    group = argParser.add_mutually_exclusive_group(required=True)
    group.add_argument('-i', '--inputs', nargs='+')     #list of paths
    group.add_argument('-f', '--inputfile', type=open)  #file with a list of paths
    group.add_argument('-d', '--inputdirectory')

    args = argParser.parse_args()
    output = open(args.outputfile, mode='a+')
    tags = args.elements

    attrs = {}
    if(args.attributes != None):
        for attr in args.attributes:
            key,val = attr.split("=")
            attrs[key] = val


    f = args.inputfile
    if f != None:
        for line in f:
            line.rstrip()
            extract(line, output, tags, attrs)

    elif args.inputs != None:
        inputs = args.inputs
        for i in inputs:
            extract(i, output, tags, attrs)
    
    else:
        for file in os.listdir(args.inputdirectory):
            extract(args.inputdirectory + file, output, tags, attrs)
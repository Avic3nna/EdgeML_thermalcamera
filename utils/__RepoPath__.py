import os
""" Get the current absolute path to the Repository on your system. 
Usefull for handling data and tests while being agnostic to current work dir
"""

path = os.path.dirname(os.path.realpath(__file__))
while 'utils' in path:
    path = os.path.abspath(path+'/..')

# To import it as whatever you want...
__RepoPath__ = path
repo_path = path

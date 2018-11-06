import os

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))

include_dirs = [
    './Include',
]


include_files = [
]

flags = [
    '-std=c++11',
]

def FlagsForFile( filename, **kwargs ):
    """
    Given a source file, retrieves the flags necessary for compiling it.
    """
    for dir in include_dirs:
        flags.append('-I' + os.path.join(CURRENT_DIR, dir))

    for file in include_files:
        flags.append('-include' + os.path.join(CURRENT_DIR, file))

    return { 'flags': flags }

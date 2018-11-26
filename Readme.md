# Sl
A tool silimilar to [sl](https://github.com/mtoyoda/sl), but used for review english words

## Install
```
git clone https://github.com/Martins3/sl
cd sl
# modify Makefile to specific the target
make
```

## How to use it
review -h

## TODO
1. Divide the review into two parts,  one is index, another is randomnized
    1. we need better way to read user config, just read file and beatify it
    2. more efficient add user config by save files
4. not only use id, but can types words to it.
2. refine the forget and success's strategy
    1. if remember one word, this word would not appear in recent 3 days(shouled be calculated more carefully), and then appear, if still, remember, it will remain silent for loonger days
    2. if forget, it will appear 
    3. not just add or substract index
3. ~~Extract data from [ECDICT](https://github.com/skywind3000/ECDICT)~~
5. Analyze words
    1. how many times forget
    2. make a chart
7. Add staragy API:
    1. every one can define his own strategy just by modify one file
8. Review notes(anything can be printed)
9. Reivew links
10. Realease with Appimgage

## Bugs

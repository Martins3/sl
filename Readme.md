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
    1. only one notes is showed
    2. cann't show in recent days
    3. propotion of words and notes, if review words 10 times, then it is very likely to review notes
9. Reivew links
10. Realease with Appimgage
11. Add a mode `learn`, go to interactive mode, and show words one by one
    1. in this mode, only words are shoulde, notes are excluded
12. Newly added words should review soon.
13. Make all the strategy into one file and use interface to handle it, by init different object, we use different strategy.
14. More easy to install for common users

15. Create a json file to recore user action
    1. how many words remember this week
    2. how many words added
    3. and so on
    4. we need to add new class for this
16. customer programmer provide .so or .dll file
    1. index is use less now
    2. a `integer` is provide, and user can read this

## Bugs
1. There is a risk that write to word.json is not reliable.
    1. maybe caused by write amtomicity
2. There are many bugs are caused by forget `make clean`, change headers, make do nothing, this rather stupid, we have to refine Makefile
3. I don't know why sort makes no sense, since no write to disk, make a random to write to disk


## Optimazation
1. It's rather stupid to read the whole database and write back when updating one line

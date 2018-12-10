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
3. Extract data from [ECDICT](https://github.com/skywind3000/ECDICT)
4. If offline, we can still learn the words
  

5. Analyze words
    1. how many times forget
    2. make a chart

8. Review notes(anything can be printed)
    1. only one notes is showed
    2. cann't show in recent days
    3. propotion of words and notes, if review words 10 times, then it is very likely to review notes

9. Reivew links

10. Realease with Appimgage
13. Make all the strategy into one file and use interface to handle it, by init different object, we use different strategy.
14. More easy to install for common users

15. Create a json file to recore user action
    1. how many words remember this week
    2. how many words added
    3. and so on
    4. we need to add new class for this

17. Use vector<Word> to vector<Word *>

18. Interface is interactive, We need a bunch of static method to beautify the line

## Bugs
1. There is a risk that write to word.json is not reliable.
    1. maybe caused by write amtomicity

## Optimazation
1. It's rather stupid to read the whole database and write back when updating one line

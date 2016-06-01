cat words.txt | tr -cs "[:alnum:]"  "\n" | sort | uniq -ci | sort -bnr | tr -s ' ' ' ' | sed 's/^\s\([0-9]*\)\s*\([a-z]*\)/\2 \1/'


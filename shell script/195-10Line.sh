#will print out unexpected line when file line's not enough
head -n10 file2.txt | tail -n1
#will print out unexpected line when file line's not enough

tail -n+10 file2.txt | head -1
sed -n '10p' file2.txt

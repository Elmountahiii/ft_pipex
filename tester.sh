#!/bin/bash
Reset="\033[0m"
FgBlack="\033[30m"
FgRed="\033[31m"
FgGreen="\033[32m"
FgYellow="\033[33m"
FgBlue="\033[34m"
FgMagenta="\033[35m"
FgCyan="\033[36m"
FgWhite="\033[37m"


test1="./pipex infile.txt \"cat\" \"wc -l\" output.txt"
ptest1="< infile.txt cat | wc -l > poutput.txt"


file="./output.txt"
pfile="./poutput.txt"
printf "${FgBlue}Testing ...${FgBlue}\n"
printf "build the project : \n"
make -s
printf "${FgGreen}done building the project${FgGreen}\n"
printf "${FgBlue}running the tests ${FgBlue}: \n"

# 1
eval $test1
eval $ptest1
content=$(cat $file)
pconstent=$(cat $pfile)
if [ "$content" = "$pconstent" ]; then
	printf "${FgGreen}test 1 : ok${FgGreen}\n"
else
{
	printf "${FgRed}test 1 : KO${FgRed}\n"
	printf "${FgRed}expected : ${pconstent}${FgRed}\n"
	printf "${FgRed}got : ${content}${FgRed}\n"
}
fi

# 2
test2="./pipex iniile.txt \"cat\" \"wc -l\" output.txt"
ptest2="< iniile.txt cat | wc -l > poutput.txt"
eval $test2
eval $ptest2



printf "${FgGreen}done running the tests${FgGreen}\n"

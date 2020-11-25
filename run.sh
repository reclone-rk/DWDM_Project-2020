#!/bin/sh
echo -e "\033[1m******** Mining top- k co-occurrence items with sequential pattern ***********\033[0m\n\n"

echo -e "\033[1mCreating Dataset...\033[0m\n\n"
function ProgressBar {
# Process data
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
# Build progressbar string lengths
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")

# 1.2 Build progressbar strings and print the ProgressBar line
# 1.2.1 Output example:                           
# 1.2.1.1 Progress : [########################################] 100%
printf "\r\033[1mProgress\033[0m : [${_fill// /#}${_empty// /-}] ${_progress}%%"

}

function LoadingDataset {
# Process data
    let _progress=(${1}*100/${2}*100)/100
    let _done=(${_progress}*4)/10
    let _left=40-$_done
# Build progressbar string lengths
    _fill=$(printf "%${_done}s")
    _empty=$(printf "%${_left}s")

# 1.2 Build progressbar strings and print the ProgressBar line
# 1.2.1 Output example:                           
# 1.2.1.1 Progress : [########################################] 100%
printf "\rLoading Dataset : [${_fill// /#}${_empty// /-}] ${_progress}%%"

}

# Variables
start=`date +%s`
_start=1

# This accounts as the "totalState" variable for the ProgressBar function
_end=100

# Proof of concept
for number in $(seq ${_start} ${_end})
do
    sleep 0.1
    ProgressBar ${number} ${_end}
done
cd dataset
g++ generator.cpp
./a.out
cd ..
end=`date +%s`
runtime=$((end-start))
printf '\n\033[1mDataset Created!\033[0m\n'
# echo $runtime Seconds.

# Running NAM algorithm
printf '\nRunning NAM algorithm...\n'
g++ NAM.cpp
for number in $(seq ${_start} ${_end})
do
    sleep 0.05
    LoadingDataset ${number} ${_end}
done
./a.out
printf '\nNAM Completed!\n'




# Running VAM algorithm
printf '\nRunning VAM algorithm...\n'
g++ VAM.cpp
for number in $(seq ${_start} ${_end})
do
    sleep 0.05
    LoadingDataset ${number} ${_end}
done
./a.out
printf '\n\n VAM Completed!\n\n'




#Running VIAM Algorithm

printf '\nRunning VIAM algorithm...\n'
g++ VIAM.cpp
for number in $(seq ${_start} ${_end})
do
    sleep 0.05
    LoadingDataset ${number} ${_end}
done
./a.out
echo -e "\033[1mVIAM Completed!\033[0m\n\n"
# printf '\n\n VIAM Completed!\n\n'


to=$2
from=$1

ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; echo $ARG; ./push_swap $ARG | wc -l
rm -rf .*~
rm -rf *~

# ./checker -v $ARG
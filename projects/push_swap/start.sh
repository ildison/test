to=$2
from=$1

ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker $ARG -v
rm -rf .*~
rm -rf *~

# ./checker -v $ARG
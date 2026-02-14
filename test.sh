#!/bin/bash

# Colors
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
CYAN="\033[1;36m"
RESET="\033[0m"

# Configuration: [Size of stack] [Number of tests] [Warning Limit]
# Feel free to adjust these limits based on project requirements
declare -a TESTS=(
    "3 10 3"      # 3 numbers, 10 times, max 3 moves
    "5 10 12"     # 5 numbers, 10 times, max 12 moves
    "100 50 700"  # 100 numbers, 50 times, < 700 is great
    "500 50 5500" # 500 numbers, 50 times, < 5500 is great
)

check_binaries() {
    if [ ! -f push_swap ]; then
        echo -e "${RED}❌ push_swap not found.${RESET}" ; exit 1
    fi
    # If using the system checker (macOS) or your own
    CHECKER="./checker"
    if [ ! -f $CHECKER ]; then
        CHECKER="checker_linux" # Common name for the provided binary
    fi
}

run_test() {
    local size=$1
    local iterations=$2
    local limit=$3
    local total_moves=0
    local max_moves=0
    local failed=0

    echo -e "${CYAN}Testing size $size ($iterations times, limit: $limit)...${RESET}"

    for i in $(seq 1 $iterations); do
        ARG=$(shuf -i 0-2000 -n $size | tr '\n' ' ')
        MOVES=$(./push_swap $ARG | wc -l)
        RESULT=$(./push_swap $ARG | ./$CHECKER $ARG)

        if [ "$RESULT" != "OK" ]; then
            echo -e "${RED}  ✘ Test $i: FAILED (Checker said $RESULT)${RESET}"
            failed=$((failed + 1))
        else
            total_moves=$((total_moves + MOVES))
            [ $MOVES -gt $max_moves ] && max_moves=$MOVES
            
            if [ $MOVES -gt $limit ]; then
                echo -e "  ${YELLOW}⚠ Test $i: OK but $MOVES moves (Limit: $limit)${RESET}"
            fi
        fi
    done

    if [ $failed -eq 0 ]; then
        avg=$((total_moves / iterations))
        echo -e "${GREEN}  AVERAGE: $avg | MAX: $max_moves${RESET}"
    else
        echo -e "${RED}  $failed tests failed correctness check.${RESET}"
    fi
    echo "------------------------------------"
}

# Main Execution
check_binaries
echo -e "${YELLOW}Starting Stress Test...${RESET}"

for t in "${TESTS[@]}"; do
    run_test $t
done
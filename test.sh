#!/bin/bash

# ==========================
# Push Swap Automated Tester
# ==========================

# Colors
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

# Check binaries
if [ ! -f push_swap ]; then
    echo -e "${RED}❌ push_swap binary not found.${RESET}"
    exit 1
fi

if [ ! -f checker ]; then
    echo -e "${RED}❌ checker binary not found.${RESET}"
    exit 1
fi

echo -e "${GREEN}✅ push_swap and checker found.${RESET}"

PASSED=1

# --------------------------
# Fixed test cases
# --------------------------
FIXED_TESTS=(
"2 1"
"3 2 1"
"4 7 2 0"
"5 1 2 3 4"
"42 17 68 99 3 0"
)

echo -e "${YELLOW}Running fixed test cases...${RESET}"

for test in "${FIXED_TESTS[@]}"; do
    RESULT=$(./push_swap $test | ./checker $test)
    if [ "$RESULT" = "OK" ]; then
        echo -e "Test [$test]: ${GREEN}Passed${RESET}"
    else
        echo -e "Test [$test]: ${RED}Failed${RESET}"
        PASSED=0
    fi
done

# --------------------------
# Random test cases
# --------------------------
echo -e "${YELLOW}Running 10 random test cases (5 numbers each)...${RESET}"

for i in $(seq 1 10); do
    RANDOM_TEST=$(shuf -i 0-100 -n 5 | tr '\n' ' ')
    RESULT=$(./push_swap $RANDOM_TEST | ./checker $RANDOM_TEST)
    if [ "$RESULT" = "OK" ]; then
        echo -e "Random Test $i [$RANDOM_TEST]: ${GREEN}Passed${RESET}"
    else
        echo -e "Random Test $i [$RANDOM_TEST]: ${RED}Failed${RESET}"
        PASSED=0
    fi
done

# --------------------------
# Summary
# --------------------------
echo -e "${YELLOW}----------------------------------${RESET}"
if [ $PASSED -eq 1 ]; then
    echo -e "${GREEN}🎉 All tests passed! Ready to push.${RESET}"
else
    echo -e "${RED}❌ Some tests failed. Fix your algorithm before pushing.${RESET}"
fi

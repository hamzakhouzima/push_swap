#!/bin/bash

# Configuration: Ensure your push_swap executable is in the same folder
EXE="./push_swap"

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

test_case() {
    local label=$1
    local input=$2
    echo -n "Testing $label: "
    
    # Capture stderr and stdout
    RESULT=$($EXE $input 2>&1)
    
    if [[ "$3" == "Error" ]]; then
        if [[ "$RESULT" == "Error" ]]; then
            echo -e "${GREEN}PASS (Correctly showed Error)${NC}"
        else
            echo -e "${RED}FAIL (Expected 'Error' but got: '$RESULT')${NC}"
        fi
    else
        # For valid cases, it shouldn't print Error (it can be empty if already sorted)
        if [[ "$RESULT" == "Error" ]]; then
            echo -e "${RED}FAIL (Got 'Error' on valid input)${NC}"
        else
            echo -e "${GREEN}PASS${NC}"
        fi
    fi
}

echo -e "${YELLOW}--- STARTING PUSH_SWAP EDGE CASE TESTS ---${NC}\n"

# 1. Non-numeric input
test_case "Non-numeric (abc)" "1 2 abc 4" "Error"
test_case "Special characters" "1 2 @ 4" "Error"

# 2. Duplicates
test_case "Duplicate numbers" "1 2 3 2" "Error"
test_case "Duplicate zeros" "0 5 0" "Error"

# 3. Integer Limits (Assuming 32-bit ints)
test_case "Overflow (MAX_INT + 1)" "2147483648" "Error"
test_case "Underflow (MIN_INT - 1)" "-2147483649" "Error"
test_case "Extreme Overflow" "9999999999999999" "Error"

# 4. Formatting Issues
test_case "Empty string" "" "" 
test_case "Multiple spaces" "1   3      2" ""
test_case "Sign without number (+)" "1 + 2" "Error"
test_case "Sign without number (-)" "1 - 2" "Error"
test_case "Double sign" "--1 2" "Error"

# 5. Small Valid Sets
test_case "Single number" "42" ""
test_case "Already sorted" "1 2 3" ""
test_case "Reverse sorted" "3 2 1" ""

echo -e "\n${YELLOW}--- TESTS COMPLETE ---${NC}"

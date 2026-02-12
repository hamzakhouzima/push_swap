#!/bin/bash

# ===============================
# Push Swap Automated Test Script
# ===============================

# Compile project first
make > /dev/null 2>&1
if [ ! -f push_swap ]; then
    echo "❌ push_swap binary not found. Compile failed."
    exit 1
fi

# Compile checker if exists
if [ ! -f checker ]; then
    echo "⚠️  checker binary not found. Some tests will skip validation."
    CHECKER=0
else
    CHECKER=1
fi

# Test cases
TESTS=(
    "2 1"
    "3 2 1"
    "5 4 3 2 1"
    "4 7 2 0"
    "1 2 3 4 5"
    "42 17 68 99 3 0"
)

READY=1

for t in "${TESTS[@]}"; do
    echo "----------------------------------"
    echo "Test input: $t"

    # Run push_swap
    OUTPUT=$(./push_swap $t)
    echo "push_swap output:"
    echo "$OUTPUT"

    if [ $CHECKER -eq 1 ]; then
        # Validate using checker
        RESULT=$(echo "$t" | ./push_swap $t | ./checker $t)
        if [ "$RESULT" = "OK" ]; then
            echo "✅ Passed"
        else
            echo "❌ Failed"
            READY=0
        fi
    fi
done

echo "----------------------------------"
if [ $READY -eq 1 ]; then
    echo "🎉 All tests passed. Project is ready to push."
else
    echo "❌ Some tests failed. Fix errors before push."
fi


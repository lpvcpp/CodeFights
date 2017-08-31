bool checkPalindrome(std::string inputString) {
    return (inputString == string(inputString.rbegin(), inputString.rend())) ;
}


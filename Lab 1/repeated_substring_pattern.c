bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);
    for (int i = 1; i <= len / 2; i++) {
        bool flag = true;
        for (int j = i; j < len; j += i) {
            if (strncmp(s, s + j, i) != 0) {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

char* reverseWords(char* s) 
{
    int r = 0, w = 0;
    while (s[r] != '\0') {
        while (s[r] == ' ') r++;
        
        if (s[r] != '\0' && w > 0) {
            s[w++] = ' '; 
        }
        
        while (s[r] != ' ' && s[r] != '\0') {
            s[w++] = s[r++]; 
        }
    }
    s[w] = '\0';

    int count = 0;
    while (s[count]) {
        count++;
    }

    int start = 0;
    int end = count - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    int begin = 0;
    int last = 0;

    while (1) {
        while (s[begin] == ' ') {
            begin++;
            last++;
        }
        if (s[begin] == '\0') break;
        while (s[last] != ' ' && s[last] != '\0') {
            last++;
        }
        int tempend = last;
        int word_end = last - 1;

        int word_start = begin;
        while (word_start < word_end) {
            char temp = s[word_start];
            s[word_start] = s[word_end];
            s[word_end] = temp;
            word_start++;
            word_end--;
        }

        if (s[tempend] == '\0') {
            break;
        }

        begin = tempend + 1;
        last = begin;
    }

    return s;
}
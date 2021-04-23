// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if ((arr[i] + arr[j] == value) && (arr[i] >= 0) && (arr[j] >= 0)) {
                count = count+1;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = len-1; i >= 0; i--) {
        if (arr[i] <= value) {
            for (int j = 0; j < i; j++) {
                if ((arr[i] + arr[j] == value)
                    && (arr[i] >= 0) && (arr[j] >= 0)) {
                   count = count+1;
               }
            }
        }
    }
  return count;
}

int countPairs3(int *arr, int len, int value) {
    int value1, count = 0, middle, n, left, right;
    for (int i = 0; i < len-1; i++) {
        if (arr[i] >= 0) {
        n = 0;
        left = i + 1;
        right = len;
        value1 = value-arr[i];
        while (left < right) {
                middle = left + (right - left) / 2;
                if (arr[middle] == value1) {
                        while ((arr[middle-1] == value1)
                               && (middle > i+1)) middle--;
                        while (arr[middle] == value1) middle++, n++;
                        break;
                } else if (arr[middle] > value1) {
                        right = middle;
                } else {
                        left = middle+1;
                }
            }
            count = count + n;
        }
}
return count;
}

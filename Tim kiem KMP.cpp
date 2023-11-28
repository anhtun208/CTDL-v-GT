#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void computeLPSArray(char *pattern, int M, int *lps) {
 int len = 0;
 lps[0] = 0;
 int i = 1;
 while (i < M) {
 if (pattern[i] == pattern[len]) {
 len++;
 lps[i] = len;
 i++;
 } else {
 if (len != 0) {
 len = lps[len - 1];
 } else {
 lps[i] = 0;
 i++;
 }
 }
 }
}
void KMP(char *text, char *pattern) {
 int M = strlen(pattern);
 int N = strlen(text);
 int *lps = (int *)malloc(sizeof(int) * M);
 computeLPSArray(pattern, M, lps);
 int i = 0;
 int j = 0; 
 while (i < N) {
 if (pattern[j] == text[i]) {
 j++;
 i++;
 }
 if (j == M) {
 printf("Tim thay chuoi con tai vi tri %d\n", i - j);
 j = lps[j - 1];
 } else if (i < N && pattern[j] != text[i]) {
 if (j != 0) {
 j = lps[j - 1];
 } else {
 i++;
 }
 }
 }
 free(lps);
}
int main() {
 char V[] = "abdcababdcabdcb";
 char P[] = "abdcabd";
 KMP(V, P);
 return 0;
}

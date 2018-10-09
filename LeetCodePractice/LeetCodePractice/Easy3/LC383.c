/*
 
 Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 
 Each letter in the magazine string can only be used once in your ransom note.
 
 Note:
 You may assume that both strings contain only lowercase letters.
 
 canConstruct("a", "b") -> false
 canConstruct("aa", "ab") -> false
 canConstruct("aa", "aab") -> true

 */

#include "LC383.h"

/* java
 
public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] arr = new int[26];
        for (int i = 0; i < magazine.length(); i++) {
            arr[magazine.charAt(i) - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if(--arr[ransomNote.charAt(i)-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
 
} */

//该c代码过不了LC的一个case 但相同的java代码却可以，java代码附在上面
bool canConstruct(char* ransomNote, char* magazine) {
    
    char repo[26];
    memset(repo, 0, 26*sizeof(char));
    
    
    unsigned long ransomLength = strlen(ransomNote);
    unsigned long magazineLength = strlen(magazine);
    
    for (int i = 0; i < magazineLength; i++) {
        repo[magazine[i] - 'a']++;
    }
    
    for (int i = 0; i < ransomLength; i++) {
        if (--repo[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    
    return true;
}

//注：以下是错误的解法
bool canConstructError(char* ransomNote, char* magazine) {
    
    int note;
    unsigned long ransomLength = strlen(ransomNote);
    if (ransomLength == 0) {
        note = 0;
    } else {
        note = (~0 << (32 - ransomLength));
    }
    
    unsigned long magazineLength = strlen(magazine);
    
    for (int i = 0; i < magazineLength; i++) {
        
        for (int j = 0; j < ransomLength; j++) {
            
            //查看标记
            int tempNote = 1;
            tempNote <<= (32 - j - 1);
            
            if ((note & tempNote) && ransomNote[j] == magazine[i]) {
                //存在
                note ^= tempNote;
                
                if (note == 0) {
                    return true;
                }
                
                break;
            } else {
                continue;
            }
        }
    }
    
    return note == 0;
}


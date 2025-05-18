/* 

//NOTES : 32 signed integer range -> -2^32  to 2^32-1
//Approach :
1) Last digit nikalenge by %10
2) result me push krenge ( rev * 10 + digit )
3) push krne se phle check krenge ki overflow na ho mtlb 32-bit me hi rhe 
*/

class Solution {
public:
    int reverse(int x) {

        //if x is less than 0 , aur uska last digit 0 ho pr number 0 na ho 
        // to bhi woh number palindrome nhi bnega

        if(x < 0 || x%10 == 0 && x != 0) return false;
        //loop jbtk chlega jb tk number reversedhalf se bada h0
        int reversedhalf = 0;
        while(x>reversedhalf){
            reversedhalf = reversedhalf*10 + x%10;
            x/= 10;

        }

    }
};

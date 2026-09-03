class Solution {
public:
    unordered_map<int,string> mp;
    void initialize(){
        mp[1]="I";
        mp[4]="IV";
        mp[5]="V";
        mp[9]="IX";
        mp[10]="X";
        mp[40]="XL";
        mp[50]="L";
        mp[90]="XC";
        mp[100]="C";
        mp[400]="CD";
        mp[500]="D";
        mp[900]="CM";
        mp[1000]="M";
    }
    int calculate_first_digit(int num){
        int last_digit;

        while(num!=0){
            last_digit=num;
            num/=10;
        }
        return last_digit;
    }
    string append(int count ,string s){
        string ans="";
        while(count--){
            ans+=s;
        }
        return ans;
    } 
    string helper(int num){
        if(num==0) return "";
        int first_digit=calculate_first_digit(num);

        if(first_digit==4 || first_digit==9){
            //find the next larger char in roman
            if(num>=900){
                num-=900;
                return mp[900] + helper(num);
            }
            else if(num>=400){
                num-=400;
                return mp[400] + helper(num);
            }
            else if(num>=90){
                num-=90;
                return mp[90] + helper(num);
            }
            else if(num>=40){
                num-=40;
                return mp[40] + helper(num);
            }
            else if(num==9){
                return mp[9];
            }
            else return mp[4];
        }
        string ans="";
        int count=0;

        while(num>=1000){
            count++;
            num-=1000;
        }
        if(count>0){
            ans = append(count,mp[1000]);
            return ans + helper(num);
        }

        while(num>=500){
            count++;
            num-=500;
        }
        if(count>0) return ans = append(count,mp[500]) + helper(num);

        while(num>=100){
            count++;
            num-=100;
        }
        if(count>0) return ans = append(count,mp[100]) + helper(num);

        while(num>=50){
            count++;
            num-=50;
        }
        if(count>0) return ans = append(count,mp[50]) + helper(num);

        while(num>=10){
            count++;
            num-=10;
        }
        if(count>0) return ans = append(count,mp[10]) + helper(num);

        while(num>=5){
            count++;
            num-=5;
        }
        if(count>0) return ans = append(count,mp[5]) + helper(num);

         while(num>=1){
            count++;
            num-=1;
        }
        if(count>0) return ans = append(count,mp[1]) + helper(num);

        return "";

    }
    string intToRoman(int num) {
        initialize();
        // string ans="";
        return helper(num);

    }
};
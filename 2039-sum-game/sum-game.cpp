class Solution {
public:
    int f(string & num,int i,int j){
        int count=0;
        for(int x=i;x<=j;x++){
            if(num[x]=='?') count++;
        }
        return count;
    }
    int sum(string & num,int i,int j){
        int sum=0;

        for(int x=i;x<=j;x++){
            if(num[x]=='?') continue;
            else{
                sum+=num[x]-'0';
            }
        }
        return sum;
    }
    bool sumGame(string num) {
        int n=num.length();

        int leftsum=sum(num,0,n/2-1);
        int rightsum=sum(num,n/2,n-1);
        int left_choices=f(num,0,n/2-1);
        int right_choices=f(num,n/2,n-1);

        int total_choices=left_choices+right_choices;

        if(total_choices%2==1) return true;//choices are odd alice paly last and alaways wins
        
        //choices are even bob play last

        //3 cases

        //choices are equal
        if(left_choices==right_choices){
            if(leftsum==rightsum) return false;
            return true;
        }

        //left choice is greater

        // if(left_choices>right_choices){
        //     //i will have alaways bob to end 
        //     // AB AB on the left side
        //     if(leftsum==rightsum) return false;
        //     else if(leftsum<rightsum){
        //         if(rightsum>9){
        //             return false;
        //         }
        //         else return true;
        //     }
        //     else{
        //         if(rightsum>9){
        //             return false;
        //         }
        //         else return true;
        //     }

        // }

        if((leftsum-rightsum)%9==0){
            if((right_choices-left_choices)/2 == (leftsum-rightsum)/9) return false;
            else return true;
        }
        if((rightsum-leftsum)%9==0){
            if((left_choices-right_choices)/2 == (leftsum-rightsum)/9) return false;
            return true;
        }

        return true;
    }
};
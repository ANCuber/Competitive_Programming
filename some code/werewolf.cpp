#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h> //fuctions for sleep
//basic settings
using namespace std;
int day;//day
int numplayer = 12;
int role[12] = {1,1,1,1,9,9,9,9,2,3,4,5};  //role
char player[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'}; //player
int live[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
int templive[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
int minn = 4;
int god = 4;
int bad = 4;//good people bad people count
int winlose = 0; //which side win
int witchkill = 999;
int wolfkill = 999;//who was killed
int votekill = 999;
int livepotion = 1;
int poison = 1;//witch's action
int guardtarget[2] = {99,98};//guard's list

//shuffle stuff,eg.role
void shuffle(){
    cout<<"Shuffling..."<<endl;
    srand((unsigned)time(NULL));
    for(int i =0;i<200;i++){
        int s = rand()%12;
        int t = rand()%12;
        int temp = role[s];
        role[s] = role[t];
        role[t] = temp;//swaping
        }
    cout<<"Shuffle complete successfully."<<endl;//the role array is now random
}

//find the role
int findrole(int m){
    int i;
    for(i = 0; i < 12; i++){
        if(role[i] == m){
         break;
        }
    }
    return i;//an usful function to find a role position
}

//action for killing or saving a victim
void kill(char k){
    int i = k - 'A';
    templive[i] = templive[i]*(-1);
    cout<<"Action complete succussfully."<<endl;
    sleep(3);
}
//besides from werewolves, god can also revive a person through *(-1) to the elements in live array
//example: witch's potion uses the function kill()

//function for the guard
void guard(int alive,int phase){
    if(alive == 1 && phase ==1){
        cout<<"\a"<<endl;
        cout<<"night "<<day<<endl;
        cout<<"Guard, open your eyes."<<endl;
        char target, done;
        int k;
        while(true){
            guarding:
            cout<<"Choose the one you want to protect.(Captialized!!!)"<<endl;
            cin>>target;
            k = target-'A';
            if(k>=0&&k<=11){
                guardtarget[day%2] = k;
                if(guardtarget[0]==guardtarget[1]){
                    cout<<"You can't protect the same person two nights a row"<<endl<<endl;
                    goto guarding;
                }
                cout<<"Action complete successfully."<<endl;
                cout<<"Enter anything to end your round."<<endl;
                cin>>done;
                break;
            }else{
                cout<<"Wrong input. Try again!"<<endl<<endl;
            }
        }
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        sleep(3);
    }else if(alive ==1&& phase ==2){
        if(guardtarget[day%2]== wolfkill){
            kill(player[wolfkill]);
        }
    }else{
        cout<<"\a"<<endl;
        cout<<"You are dead."<<endl;
        sleep(5);
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}
//guard can protect a person from getting killed by the werewolves;
//however, he does NOT protect person from witch's poison

//function for the wolf
void wolf(){
    cout<<"\a"<<endl;
    cout<<"night "<<day<<endl;
    char target;
    cout<<"Werewolves, open your eyes."<<endl;
    cout<<"Discuss the one to kill."<<endl;
    cout<<"You have one minute."<<endl;
    sleep(5);
    cout<<"Time is up. Choose a victim.(Capitalized!!!)"<<endl;
    cin>>target;
    kill(target);
    wolfkill = target-'A';
    cout<<"Close your eyes."<<endl;
    sleep(3);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
//wolf can kill a person each night

//function for the seer
void seer(int alive){
    if(alive == 1){
        cout<<"\a"<<endl;
        cout<<"night "<<day<<endl;
        cout<<"Seer, open your eyes."<<endl;
        char target, done;
        int k;
        while(true){
            cout<<"Choose the one you want to peek.(Captialized!!!)"<<endl;
            cin>>target;
            k = target-'A';
            if(k>=0&&k<=11){
                cout<<"One's role is : "<<role[k]<<endl;
                cout<<"Enter anything to end your round."<<endl;
                cin>>done;
                break;
            }else{
                cout<<"Wrong input. Try again!"<<endl<<endl;
            }
        }
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        sleep(3);
    }else{
        cout<<"\a"<<endl;
        cout<<"You are dead."<<endl;
        sleep(5);
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}
//seer can look at one person's role each night

//function for witch
void witch(int alive){
    if(alive == 1){
        cout<<"\a"<<endl;
        cout<<"night "<<day<<endl;
        char will;
        string done;
        int willint;
        cout<<"Witch, open your eyes."<<endl;
        if(livepotion ==1){
            while(true){
                cout<<player[wolfkill]<<" was dead.Would you like to use your potion?"<<endl;
                cout<<"(y = yes  n = no)"<<endl;
                cin>>will;
                willint = will-'a';
                if(willint == 'y'-'a'){
                    kill(player[wolfkill]);
                    livepotion = livepotion -1;
                    break;
                }else if( willint == 'n'-'a'){
                    cout<<"potion remain : "<<livepotion<<endl<<endl;
                    break;
                }else{
                    cout<<"Wrong input.Try again"<<endl<<endl;
                }
            }
        }else{
            cout<<"No potion remaining."<<endl;
        }
        will = 'r';
        if(poison ==1){
            while(true){
                cout<<"Would you like to use your poison?"<<endl;
                cout<<"(y = yes  n = no)"<<endl;
                cin>>will;
                willint = will-'a';
                if(willint == 'y'-'a'){
                    cout<<"Who would you like to kill?"<<endl;
                    cin>>will;
                    if(will == player[wolfkill]){
                        guardtarget[day%2]= -1;//guard+poison == dead
                        cout<<"Action complete succussfully."<<endl;
                        sleep(3);
                        poison = poison -1;
                    }else{
                        kill(will);
                        poison = poison -1;
                    }
                    break;
                }else if( willint == 'n'-'a'){
                    cout<<"poison remain : "<<poison<<endl<<endl;
                    break;
                }else{
                    cout<<"Wrong input.Try again"<<endl<<endl;
                }
            }
        }else{
            cout<<"No poison remaining."<<endl;
        }
        cout<<"Enter anything to end your round."<<endl;
        cin>>done;
        sleep(3);
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    }else{
        cout<<"\a"<<endl;
        cout<<"You are dead."<<endl;
        sleep(5);
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}
//witch has a potion(save live) and a poison (kill)

//function for hunter
void hunter(int alive){
    char will,done;
    if((alive == -1 && findrole(4)== votekill)||(alive == -1 && findrole(4)==wolfkill)){
        cout<<player[findrole(4)]<<" is hunter.Who would you want to kill?"<<endl;
        cin>>will;
        kill(will);
        cout<<will<<" is dead."<<endl;
        cout<<"Enter any key to continue."<<endl;
        live[findrole(4)] = 0;
        cin>>done;
    }
}
//can kill one person when dead

//function for idiot
void idiot(int alive){
    char done;
    cout<<votekill<<endl;
    if((alive != 1) && (findrole(5) == votekill)){
        cout<<findrole(5)<<" is idiot.He can't be killed through voting."<<endl;
        kill(player[findrole(5)]);
        cout<<player[findrole(5)]<<" is NOT out."<<endl;
        cout<<"Enter any key to continue."<<endl;
        cin>>done;
    }else{
        cout<<"Not idiot."<<endl;
    }
}

//discuss time control
void discuss(int time){
    cout<<"Player ";
    for(int i = 0;i<numplayer;i++){
        if(live[i]!=1){
            cout<<player[i]<<" ";
            cout<<"is dead."<<endl;
        }
    }
    cout<<time/60<<" minutes to discuss."<<endl;
    sleep(time);
}

//voting
void vote(){
    char out;
    int outint;
    cout<<"\aTime is up. Who is out?"<<endl;
    cin>>out;
    outint = out-'A';
    live[outint] = (-1);
    votekill = outint;
    cout<<out<<" is out."<<endl;
}

//refresh current status
void refresh(){
    minn = 4;
    god = 4;
    bad =4;
    for(int i = 0; i<numplayer; i++){
        if(live[i]!=1){
            if(role[i]==9){
                bad = bad-1;
            }else if(role[i]==1){
                minn = minn-1;
            }else{
                god = god-1;
            }
        }
    }
    if(bad == 0){
        winlose = 1;
    }
    if( minn==0 || god==0){
        winlose = 9;
    }
}
//to check whether the game should be over or not

//day 0 role reveal
void role_reveal(int m,char setting){
    if(setting == 'a'||setting  == 'A'){
        for(int i = 0;i<12;i++){
        string a;
        int skip = 0;
        cout<<player[i]<<" your role : "<<role[i]<<endl;
        cout<<"(1 = villager 2 = seer 3 = witch 4 = hunter 5 = guard 9 = werewolf)"<<endl;
        cout<<"Enter ok to continue."<<endl;
        while(true){
            cin>>a;
            if(a == "ok" || a == "OK"){
                sleep(3);
                break;
            }
            if(a == "skip"){
                skip = 1;
                break;
            }
        }
        if(skip == 1){
            break;
        }
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<"\a";
    }
    sleep(1);
    }else if(setting == 'b'||setting  == 'B'){
        for(int i = 0;i<12;i++){
            string a;
            int skip = 0;
            cout<<player[i]<<" your role : "<<role[i]<<endl;
            cout<<"(1 = villager 2 = seer 3 = witch 4 = hunter 5 = idiot 9 = werewolf)"<<endl;
            cout<<"Enter ok to continue."<<endl;
            while(true){
                cin>>a;
                if(a == "ok" || a == "OK"){
                    sleep(3);
                    break;
                }
                if(a == "skip"){
                    skip = 1;
                    break;
                }
            }
            if(skip == 1){
                break;
            }
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<"\a";
        }
    sleep(1);
    }else{
        cout<<"program crashed."<<endl;
    }
}
//everyone can get their role without knowing others


int main(){
    day =0;
    cout<<"Welcome to the game of werewolf!"<<endl;
    cout<<"Created by ckmsc39th_25_03 Austin."<<endl<<endl;
    cout<<"Choose a setting"<<endl;
    cout<<"A : villagers*4 / werewolf*4 / seer*1 / witch*1 / hunter*1 / guard*1"<<endl;
    cout<<"B : villagers*4 / werewolf*4 / seer*1 / witch*1 / hunter*1 / idiot*1"<<endl;

    day0:
    char setting = 'o';
    cin>>setting;
    if( setting == 'A'||setting == 'a'){
        cout<<endl<<"You chose setting A."<<endl;
            while(true){
            string a;
            cin>>a;
            if(a == "start"){
                day = 1;
                cout<<"starting..."<<endl;
                shuffle();
                cout<<"\a";
                for(int i=0;i<numplayer;i++){
                cout<<player[i]<<" : "<<role[i]<<endl;
                }
                cout<<"(1 = villager 2 = seer 3 = witch 4 = hunter 5 = guard 9 = werewolf)"<<endl;
                role_reveal(12,setting);
                cout<<"Please close your eyes"<<"\a"<<endl;
                sleep(7);
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                break;
                }
            }
        while(true){
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            guard(live[findrole(4)],1);
            wolf();
            seer(live[findrole(2)]);
            witch(live[findrole(3)]);
            guard(live[findrole(5)],2);
            //conclude the actions at night
            for(int i = 0;i<numplayer;i++){
                live[i] = templive[i];
                /*cout<<live[i]<<" ";
                sleep(1);*/
            }
            cout<<"\aday "<<day<<endl;
            hunter(live[findrole(4)]);
            refresh();
            if(winlose == 1 || winlose ==9){
                break;
            }
            discuss(10);
            vote();
            hunter(live[findrole(4)]);
            refresh();
            if(winlose == 1 || winlose ==9){
                break;
            }
            cout<<"Please close your eyes."<<endl;
            sleep(5);
            day = day+1;
        }
    }else if( setting == 'B'||setting == 'b'){
        cout<<endl<<"You chose setting B."<<endl;
            while(true){
            string a;
            cin>>a;
            if(a == "start"){
                day = 1;
                cout<<"starting..."<<endl;
                shuffle();
                cout<<"\a";
                for(int i=0;i<numplayer;i++){
                cout<<player[i]<<" : "<<role[i]<<endl;
                }
                cout<<"(1 = villager 2 = seer 3 = witch 4 = hunter 5 = idiot 9 = werewolf)"<<endl;
                cout<<"Hand the computer to A."<<endl;
                sleep(3);
                role_reveal(numplayer,setting);
                cout<<"Please close your eyes"<<"\a"<<endl;
                sleep(7);
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                break;
                }
            }
        while(true){
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            wolf();
            seer(live[findrole(2)]);
            witch(live[findrole(3)]);
            //conclude the actions at night
            cout<<"\aday "<<day<<endl;
            hunter(live[findrole(4)]);
            refresh();
            if((winlose == 1) || (winlose ==9)){
                break;
            }
            discuss(5);
            vote();
            cout<<votekill<<" "<<findrole(5)<<endl;
            for(int i=0;i<12;i++){
                cout<<live[i]<<" ";
                sleep(1);
            }
            refresh();
            idiot(live[findrole(5)]);
            hunter(live[findrole(4)]);
            refresh();
            if((winlose == 1) || (winlose ==9)){
                break;
            }
            cout<<"Please close your eyes."<<endl;
            sleep(5);
            day = day+1;
            }
        }else{
        cout<<"wrong input. try again."<<endl;
        goto day0;
    }
    cout<<endl<<endl;
    if(winlose==1){
        cout<<"The village team win."<<endl;
    }else if(winlose == 9){
        cout<<"The werewolves team win."<<endl;
    }
    cout<<"Revealing the roles..."<<endl;
    for(int i=0;i<12;i++){
        cout<<player[i]<<" : "<<role[i]<<endl;
    }
    cout<<"(1 = villager 2 = seer 3 = witch 4 = hunter 5 = guard 9 = werewolf)"<<endl;
    return 0;
}
/*if(a == "quit"){
                cout<<"Revealing the roles..."<<endl;
                for(int i=0;i<12;i++){
                    cout<<player[i]<<" : "<<role[i]<<endl;
                    }
                cout<<"(1 = villager 2 = seer 3 = witch 4 = hunter 5 = guard 9 = werewolf)"<<endl;
                break;
                }*/


#include<iostream>
int numberOfPeople;
int numberOfTrials;
using namespace std;

double runTest(int people,int trials,int result[]); // run the test
int getRandomBirthdate();       // generating random birthdays in format ddmmyyy e.g 30011990
int compareBirthdays(int people[],int peoplNumber);   // comparing birthdays

int main(){
  srand(time(0));
  cout<<"Enter number of people in the room.\n";
  cin>>numberOfPeople;
  cout<<"Number of trials.\n";
  cin>>numberOfTrials;
  int trialResult[numberOfTrials];   // array to save results
  double probability = runTest(numberOfPeople,numberOfTrials,trialResult);
  cout<<"Probability is :"<<probability<<endl;
}

double runTest(int people,int trials,int result[]){
  int peopleBirthdays[people];  // array to save birthdays in each iteration
  for(int i=0;i<trials;i++){
    for(int j=0;j<people;j++){
      peopleBirthdays[j]=getRandomBirthdate();
    }
    result[i]=compareBirthdays(peopleBirthdays,numberOfPeople);
  }

  // to check number of times two or more people had same birthdays
  double count=0;
  for(int i=0;i<trials;i++){
    if(result[i]>0){
      count++;
    }
  }
  return count/trials;
}

// to generate random birthdays
int getRandomBirthdate(){
  int month = rand()%12+1;      // generating random month
  int year = rand()%200+1800;   // year between 1800-2000
  int day;
  if(year%4==0&&month==2){
    day = rand()%29+1;          // if its leap year and month is feburary
  }else if(month==2&&year%4!=0){
    day = rand()%28+1;          // if month is feb and not a leap year
  }else{
    day = (month%2==0)?(rand()%31+1):(rand()%30+1);   // if month is not feb generating date according to month
  }
  return (day*1000000)+(month*10000)+(year);
}


// to compare birthdays from array
int compareBirthdays(int people[],int peoplNumber){
  int same=0;
  int year1,year2;
  for(int h=0;h<peoplNumber-1;h++){
      if(people[h]%4!=0){    // year1 should not be leap year
        for(int l=h+1;l<peoplNumber;l++){
          if(people[h]==people[l]&&people[l]%4!=0){ // year 2 should not be leap year
            same++;
          }
        }
      }
  }
  return same;
}

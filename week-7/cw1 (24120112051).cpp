#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    string fullName;
    int jambScore;
    int waecScore;
    int age;
    string firstChoicePAU;
    string disciplinaryRecord;
    int hostelPreference;
    int baseTuition = 1500000;
    int hostelFee = 0;
    string admissionStatus = "PENDING";
    int scholarshipPercent = 0; // tracked numerically so we can compute totals
    double tuitionAfterScholarship = 0.0;
    double totalPayable = 0.0;


    cout<<" Enter your full name: ";
    cin>> fullName;
    cout<<" \nEnter your JAMB score(0-400): ";
    cin>> jambScore;
    cout<<" \nEnter your WAEC average score (0-100): ";
    cin >> waecScore; // read WAEC score
    cout<<" \nEnter your Age(in years): ";
    cin>> age;
    cout<<" \nWas your first choice PAU? (yes/no): ";
    cin>> firstChoicePAU;
    cout<<" \nDo you have any disciplinary record? (yes/no): ";
    cin>> disciplinaryRecord;
    cout<<" \nHostel preference(1 - 3): 1. Main Hostel (180000) 2. Annex Hostel (120000) 3. Day Student (0): ";
    cin>> hostelPreference;

    switch(hostelPreference){
        case 1:
            hostelFee = 180000;
            cout<<" You have selected Main Hostel.";
            cout<<"Fee: ₦"<<hostelFee;
            break;
        case 2:
            hostelFee = 120000;
            cout<<" You have selected Annex Hostel.";
            cout<<"Fee: ₦"<<hostelFee;
            break;
        case 3:
            hostelFee = 0;
            cout<<" You have selected Day Student option.";
            cout<<"No hostel fee required.";
            break;
        default:
            cout << "Invalid hostel preference selected." << endl;
            return 0; // Exit the program with an error code
    }
    
    // Admission Logic - set admissionStatus and maintain your output style
    
    if ((jambScore >= 220 && waecScore >= 60) && (firstChoicePAU == "yes")){
        admissionStatus = "ADMITTED";
        cout<<" \nCongratulations " << fullName << ", you have been admitted to PAU."<< endl;   
    }
    else if ((jambScore >= 200 && waecScore >= 70) && (firstChoicePAU == "yes")){
        admissionStatus = "ADMITTED";
        cout<<" \nCongratulations " << fullName << ", you have been admitted to PAU."<< endl;   
    }
    else if (( disciplinaryRecord == "yes") || (age < 16)){
        admissionStatus = "REJECTED";
        cout<<" \nSorry " << fullName << ", you are not eligible for admission to PAU."<< endl;   
    }
    else{
        admissionStatus = "PENDING";
        cout<<" \nHello " << fullName << ", your admission to PAU is PENDING further review."<< endl;
    }

    // Scholarship Evaluation (track % so we can compute final payable)
    if (jambScore >= 320) scholarshipPercent = 30;
    else if (jambScore >= 280) scholarshipPercent = 20;
    else if (jambScore >= 240) scholarshipPercent = 10;

    if (scholarshipPercent > 0) cout<<" You have been awarded a "<<scholarshipPercent<<"% scholarship."<< endl;
    else cout<<" You have not been awarded any scholarship."<< endl;

    // Bonus rule (5% extra, cap to 35%)
    if (waecScore >= 80 && firstChoicePAU == "yes") {
        cout<<" You have been awarded an additional 5% scholarship (cap total scholarship at 35%)" << endl;
        scholarshipPercent = min(35, scholarshipPercent + 5);
    } else {
        cout<<" You have not qualified for the additional 5% scholarship." << endl;
    }

    // Hostel assignment
    if ((admissionStatus == "ADMITTED") && (disciplinaryRecord == "no")){
        cout<<" You have been assigned to your preferred hostel option." << endl;
    }
    else if (admissionStatus == "PENDING"){
        cout<<" Hostel assignment is on hold until admission status is finalized." << endl;
    }
    else if (admissionStatus == "REJECTED"){
        cout<<" You are not eligible for hostel assignment"<< endl;
    }

    // Random merit grant
    // Generate r in [1,100]. If r is prime and <= 97 and admissionStatus == "ADMITTED" -> apply ₦50,000 grant
    int meritGrant = 0;
    srand((unsigned) time(NULL));
    int r = (rand() % 100) + 1; // 1..100
    cout << "\nRandom merit draw number (1-100): " << r << endl;

    // Hard-coded prime check for primes <= 97 (no loops/arrays as requested)
    bool isPrime = (r==2 || r==3 || r==5 || r==7 || r==11 || r==13 || r==17 || r==19 || r==23 || r==29 ||
                    r==31 || r==37 || r==41 || r==43 || r==47 || r==53 || r==59 || r==61 || r==67 || r==71 ||
                    r==73 || r==79 || r==83 || r==89 || r==97);
        
    int grantAmount = 50000;

    // Apply merit grant when admitted, r is prime and <= 97
    if (r <= 97 && isPrime && admissionStatus == "ADMITTED") {
        meritGrant = grantAmount;
        cout << " You have been awarded a merit grant of ₦" << grantAmount << "!" << endl;
    } else {
        cout << " You have not qualified for the merit grant." << endl;
    }
    
    // Totals calculation: apply scholarship percent correctly (percent / 100)
    tuitionAfterScholarship = baseTuition - (scholarshipPercent * baseTuition);
    totalPayable = tuitionAfterScholarship + hostelFee - meritGrant;
    if (totalPayable < 0.0) totalPayable = 0.0;

    cout << "\n--- Final payable summary ---" << endl;
    cout << "Base tuition: ₦" << baseTuition << "\n";
    cout << "Scholarship: " << scholarshipPercent << "% -> tuition after scholarship: ₦" << tuitionAfterScholarship << "\n";
    cout << "Hostel fee: ₦" << hostelFee << "\n";
    cout << "Merit grant applied: ₦" << meritGrant << "\n";
    cout << "Total payable: ₦" << totalPayable << "\n";
    
    return 0;


    
    



}

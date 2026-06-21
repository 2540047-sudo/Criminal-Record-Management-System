#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void clearScreen() {
    system("cls");
}

// ============================================================
//   VALIDATION FUNCTIONS
// ============================================================

string toUpper(string s) {
    for (int i = 0; i < (int)s.length(); i++)
        s[i] = toupper(s[i]);
    return s;
}

bool isValidString(string s) {
    if (s.empty()) return false;
    for (int i = 0; i < (int)s.length(); i++)
        if (isdigit(s[i])) return false;
    return true;
}

bool isValidInt(string s) {
    if (s.empty()) return false;
    for (int i = 0; i < (int)s.length(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}

string getValidString(string prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) { cout << "  [!] Cannot be empty. Try again.\n"; continue; }
        if (!isValidString(input)) { cout << "  [!] Letters only. No numbers allowed. Try again.\n"; continue; }
        return input;
    }
}

int getValidInt(string prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!isValidInt(input)) { cout << "  [!] Numbers only. Try again.\n"; continue; }
        return atoi(input.c_str());
    }
}

string getAnyString(string prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) { cout << "  [!] Cannot be empty. Try again.\n"; continue; }
        return input;
    }
}

string getThreatLevel() {
    string input;
    while (true) {
        cout << "  Threat Level (LOW / MEDIUM / HIGH / MOST WANTED): ";
        getline(cin, input);
        string up = toUpper(input);
        if (up == "LOW" || up == "MEDIUM" || up == "HIGH" || up == "MOST WANTED")
            return up;
        cout << "  [!] Invalid. Enter: LOW, MEDIUM, HIGH, or MOST WANTED\n";
    }
}

void pressEnter() {
    cout << "\n  Press Enter to continue...";
    cin.ignore(10000, '\n');
}

void printLine() {
    cout << "  --------------------------------------------------\n";
}

// ============================================================
//   AUTO ID GENERATORS
// ============================================================

int criminalCount = 0;
int caseCount = 0;
int evidenceCount = 0;
int arrestCount = 0;
int bailCount = 0;
int sceneCount = 0;
int hearingCount = 0;
int witnessCount = 0;
int victimCount = 0;
int notifCount = 0;
int meetingCount = 0;
int officerCount = 0;
int detectiveCount = 0;

string intToStr(int n) {
    stringstream ss; ss << n; return ss.str();
}

string genCriminalID()  { criminalCount++;  string s = intToStr(criminalCount);  while(s.length()<3) s="0"+s; return "CR-"+s; }
string genCaseID()      { caseCount++;      string s = intToStr(caseCount);      while(s.length()<3) s="0"+s; return "C-"+s; }
string genEvidenceID()  { evidenceCount++;  string s = intToStr(evidenceCount);  while(s.length()<3) s="0"+s; return "E-"+s; }
string genArrestID()    { arrestCount++;    string s = intToStr(arrestCount);    while(s.length()<3) s="0"+s; return "A-"+s; }
string genBailID()      { bailCount++;      string s = intToStr(bailCount);      while(s.length()<3) s="0"+s; return "B-"+s; }
string genSceneID()     { sceneCount++;     string s = intToStr(sceneCount);     while(s.length()<3) s="0"+s; return "SC-"+s; }
string genHearingID()   { hearingCount++;   string s = intToStr(hearingCount);   while(s.length()<3) s="0"+s; return "H-"+s; }
string genWitnessID()   { witnessCount++;   string s = intToStr(witnessCount);   while(s.length()<3) s="0"+s; return "W-"+s; }
string genVictimID()    { victimCount++;    string s = intToStr(victimCount);    while(s.length()<3) s="0"+s; return "V-"+s; }
string genNotifID()     { notifCount++;     string s = intToStr(notifCount);     while(s.length()<3) s="0"+s; return "N-"+s; }
string genMeetingID()   { meetingCount++;   string s = intToStr(meetingCount);   while(s.length()<3) s="0"+s; return "M-"+s; }
string genOfficerID()   { officerCount++;   string s = intToStr(officerCount);   while(s.length()<3) s="0"+s; return "OFC-"+s; }
string genDetectiveID() { detectiveCount++; string s = intToStr(detectiveCount); while(s.length()<3) s="0"+s; return "DET-"+s; }

// ============================================================
//   ABSTRACT BASE CLASS: Person
// ============================================================

class Person {
protected:
    string name;
    int age;
    string cnic;
    string address;
public:
    Person() { name=""; age=0; cnic=""; address=""; }
    Person(string n, int a, string c, string addr) { name=n; age=a; cnic=c; address=addr; }
    string getName()    { return name; }
    void setName(string n) { name=n; }
    int getAge()        { return age; }
    void setAge(int a)  { age=a; }
    string getCnic()    { return cnic; }
    void setCnic(string c) { cnic=c; }
    string getAddress() { return address; }
    void setAddress(string a) { address=a; }
    virtual void getDetails() = 0;
    virtual ~Person() {}
};

// ============================================================
//   ABSTRACT BASE CLASS: Case
// ============================================================

class Case {
protected:
    string caseID;
    string title;
    string date;
    string description;
    string linkedCriminalID;
    string status;
public:
    Case() { caseID=""; title=""; date=""; description=""; linkedCriminalID=""; status="Active"; }
    Case(string id, string t, string d, string desc, string cid)
        { caseID=id; title=t; date=d; description=desc; linkedCriminalID=cid; status="Active"; }
    string getCaseID()           { return caseID; }
    void setCaseID(string id)    { caseID=id; }
    string getTitle()            { return title; }
    void setTitle(string t)      { title=t; }
    string getDate()             { return date; }
    void setDate(string d)       { date=d; }
    string getDescription()      { return description; }
    void setDescription(string d){ description=d; }
    string getLinkedCriminalID() { return linkedCriminalID; }
    void setLinkedCriminalID(string id){ linkedCriminalID=id; }
    string getStatus()           { return status; }
    void setStatus(string s)     { status=s; }
    bool operator==(Case& other) { return caseID == other.caseID; }
    bool operator<(Case& other)  { return date < other.date; }
    virtual void generateReport() = 0;
    virtual ~Case() {}
};

// ============================================================
//   CRIMINAL CLASS
// ============================================================

class Criminal : public Person {
private:
    string criminalID;
    string crimeType;
    string threatLevel;
    string bailStatus;
public:
    Criminal() : Person() { criminalID=""; crimeType=""; threatLevel=""; bailStatus="Not on Bail"; }
    Criminal(string id, string n, int a, string c, string addr, string crime, string threat)
        : Person(n,a,c,addr) { criminalID=id; crimeType=crime; threatLevel=threat; bailStatus="Not on Bail"; }

    string getCriminalID()       { return criminalID; }
    void setCriminalID(string id){ criminalID=id; }
    string getCrimeType()        { return crimeType; }
    void setCrimeType(string c)  { crimeType=c; }
    string getThreatLvl()        { return threatLevel; }
    void setThreatLvl(string t)  { threatLevel=t; }
    string getBailStatus()       { return bailStatus; }
    void setBailStatus(string b) { bailStatus=b; }

    void getDetails() {
        printLine();
        cout << "  Criminal ID   : " << criminalID << "\n";
        cout << "  Name          : " << name << "\n";
        cout << "  Age           : " << age << "\n";
        cout << "  CNIC          : " << cnic << "\n";
        cout << "  Address       : " << address << "\n";
        cout << "  Crime Type    : " << crimeType << "\n";
        cout << "  Threat Level  : " << threatLevel << "\n";
        cout << "  Bail Status   : " << bailStatus << "\n";
        printLine();
    }

    // Function overloading - compile time polymorphism
    void displayInfo() {
        cout << "  [" << criminalID << "] " << name << " | " << crimeType << " | " << threatLevel << " | " << bailStatus << "\n";
    }
    void displayInfo(string filter) {
        if (toUpper(crimeType)==toUpper(filter) || toUpper(threatLevel)==toUpper(filter))
            displayInfo();
    }
    void displayInfo(string filterName, string filterThreat) {
        if (toUpper(name)==toUpper(filterName) && toUpper(threatLevel)==toUpper(filterThreat))
            displayInfo();
    }
};

// ============================================================
//   OFFICER CLASS
// ============================================================

class Officer : public Person {
private:
    string officerID;
    string username;
    string password;
    string badgeNo;
    string department;
    string rank;
public:
    Officer() : Person() { officerID=""; username=""; password=""; badgeNo=""; department=""; rank=""; }
    Officer(string id, string n, int a, string c, string addr,
            string user, string pass, string badge, string dept, string rnk)
        : Person(n,a,c,addr) { officerID=id; username=user; password=pass; badgeNo=badge; department=dept; rank=rnk; }

    string getOfficerID()        { return officerID; }
    void setOfficerID(string id) { officerID=id; }
    string getUsername()         { return username; }
    void setUsername(string u)   { username=u; }
    string getPassword()         { return password; }
    void setPassword(string p)   { password=p; }
    string getBadgeNo()          { return badgeNo; }
    void setBadgeNo(string b)    { badgeNo=b; }
    string getDepartment()       { return department; }
    void setDepartment(string d) { department=d; }
    string getRank()             { return rank; }
    void setRank(string r)       { rank=r; }

    void getDetails() {
        printLine();
        cout << "  Officer ID    : " << officerID << "\n";
        cout << "  Name          : " << name << "\n";
        cout << "  Age           : " << age << "\n";
        cout << "  CNIC          : " << cnic << "\n";
        cout << "  Address       : " << address << "\n";
        cout << "  Username      : " << username << "\n";
        cout << "  Badge No      : " << badgeNo << "\n";
        cout << "  Department    : " << department << "\n";
        cout << "  Rank          : " << rank << "\n";
        printLine();
    }
};

// ============================================================
//   DETECTIVE CLASS
// ============================================================

class Detective : public Person {
private:
    string detectiveID;
    string username;
    string password;
    string specialization;
    int caseLoad;
public:
    Detective() : Person() { detectiveID=""; username=""; password=""; specialization=""; caseLoad=0; }
    Detective(string id, string n, int a, string c, string addr,
              string user, string pass, string spec)
        : Person(n,a,c,addr) { detectiveID=id; username=user; password=pass; specialization=spec; caseLoad=0; }

    string getDetectiveID()        { return detectiveID; }
    void setDetectiveID(string id) { detectiveID=id; }
    string getUsername()           { return username; }
    void setUsername(string u)     { username=u; }
    string getPassword()           { return password; }
    void setPassword(string p)     { password=p; }
    string getSpecialization()     { return specialization; }
    void setSpecialization(string s){ specialization=s; }
    int getCaseLoad()              { return caseLoad; }
    void setCaseLoad(int c)        { caseLoad=c; }
    void increaseCaseLoad()        { caseLoad++; }
    void decreaseCaseLoad()        { if(caseLoad>0) caseLoad--; }

    void getDetails() {
        printLine();
        cout << "  Detective ID    : " << detectiveID << "\n";
        cout << "  Name            : " << name << "\n";
        cout << "  Age             : " << age << "\n";
        cout << "  CNIC            : " << cnic << "\n";
        cout << "  Address         : " << address << "\n";
        cout << "  Username        : " << username << "\n";
        cout << "  Specialization  : " << specialization << "\n";
        cout << "  Case Load       : " << caseLoad << "\n";
        printLine();
    }
};

// ============================================================
//   WITNESS CLASS
// ============================================================

class Witness : public Person {
private:
    string witnessID;
    string statement;
    string protectionStatus;
    string linkedCaseID;
    string linkedCriminalID;
public:
    Witness() : Person() { witnessID=""; statement=""; protectionStatus=""; linkedCaseID=""; linkedCriminalID=""; }
    Witness(string id, string n, int a, string c, string addr,
            string stmt, string prot, string cid, string crimid)
        : Person(n,a,c,addr) { witnessID=id; statement=stmt; protectionStatus=prot; linkedCaseID=cid; linkedCriminalID=crimid; }

    string getWitnessID()           { return witnessID; }
    void setWitnessID(string id)    { witnessID=id; }
    string getStatement()           { return statement; }
    void setStatement(string s)     { statement=s; }
    string getProtectionStatus()    { return protectionStatus; }
    void setProtectionStatus(string p){ protectionStatus=p; }
    string getLinkedCaseID()        { return linkedCaseID; }
    void setLinkedCaseID(string id) { linkedCaseID=id; }
    string getLinkedCriminalID()    { return linkedCriminalID; }
    void setLinkedCriminalID(string id){ linkedCriminalID=id; }

    void getDetails() {
        printLine();
        cout << "  Witness ID      : " << witnessID << "\n";
        cout << "  Name            : " << name << "\n";
        cout << "  Age             : " << age << "\n";
        cout << "  Statement       : " << statement << "\n";
        cout << "  Protection      : " << protectionStatus << "\n";
        cout << "  Linked Case     : " << linkedCaseID << "\n";
        cout << "  Linked Criminal : " << linkedCriminalID << "\n";
        printLine();
    }
};

// ============================================================
//   VICTIM CLASS
// ============================================================

class Victim : public Person {
private:
    string victimID;
    string injuryLevel;
    string linkedCaseID;
    string linkedCriminalID;
public:
    Victim() : Person() { victimID=""; injuryLevel=""; linkedCaseID=""; linkedCriminalID=""; }
    Victim(string id, string n, int a, string c, string addr,
           string injury, string cid, string crimid)
        : Person(n,a,c,addr) { victimID=id; injuryLevel=injury; linkedCaseID=cid; linkedCriminalID=crimid; }

    string getVictimID()            { return victimID; }
    void setVictimID(string id)     { victimID=id; }
    string getInjuryLevel()         { return injuryLevel; }
    void setInjuryLevel(string i)   { injuryLevel=i; }
    string getLinkedCaseID()        { return linkedCaseID; }
    void setLinkedCaseID(string id) { linkedCaseID=id; }
    string getLinkedCriminalID()    { return linkedCriminalID; }
    void setLinkedCriminalID(string id){ linkedCriminalID=id; }

    void getDetails() {
        printLine();
        cout << "  Victim ID       : " << victimID << "\n";
        cout << "  Name            : " << name << "\n";
        cout << "  Age             : " << age << "\n";
        cout << "  CNIC            : " << cnic << "\n";
        cout << "  Address         : " << address << "\n";
        cout << "  Injury Level    : " << injuryLevel << "\n";
        cout << "  Linked Case     : " << linkedCaseID << "\n";
        cout << "  Linked Criminal : " << linkedCriminalID << "\n";
        printLine();
    }
};

// ============================================================
//   ACTIVE CASE CLASS
// ============================================================

class ActiveCase : public Case {
private:
    string assignedDetectiveID;
    string progress;
public:
    ActiveCase() : Case() { assignedDetectiveID="Unassigned"; progress="Under Investigation"; status="Active"; }
    ActiveCase(string id, string t, string d, string desc, string cid)
        : Case(id,t,d,desc,cid) { assignedDetectiveID="Unassigned"; progress="Under Investigation"; status="Active"; }

    string getAssignedDetectiveID()        { return assignedDetectiveID; }
    void setAssignedDetectiveID(string id) { assignedDetectiveID=id; }
    string getProgress()                   { return progress; }
    void setProgress(string p)             { progress=p; }

    void generateReport() {
        printLine();
        cout << "  [ACTIVE CASE]\n";
        cout << "  Case ID         : " << caseID << "\n";
        cout << "  Title           : " << title << "\n";
        cout << "  Date            : " << date << "\n";
        cout << "  Description     : " << description << "\n";
        cout << "  Linked Criminal : " << linkedCriminalID << "\n";
        cout << "  Detective       : " << assignedDetectiveID << "\n";
        cout << "  Progress        : " << progress << "\n";
        cout << "  Status          : " << status << "\n";
        printLine();
    }
};

// ============================================================
//   CLOSED CASE CLASS
// ============================================================

class ClosedCase : public Case {
private:
    string verdict;
    string closingDate;
    string assignedDetectiveID;
public:
    ClosedCase() : Case() { verdict=""; closingDate=""; assignedDetectiveID=""; status="Closed"; }
    ClosedCase(string id, string t, string d, string desc, string cid,
               string verd, string closeDate, string detID)
        : Case(id,t,d,desc,cid) { verdict=verd; closingDate=closeDate; assignedDetectiveID=detID; status="Closed"; }

    string getVerdict()                    { return verdict; }
    void setVerdict(string v)              { verdict=v; }
    string getClosingDate()                { return closingDate; }
    void setClosingDate(string d)          { closingDate=d; }
    string getAssignedDetectiveID()        { return assignedDetectiveID; }
    void setAssignedDetectiveID(string id) { assignedDetectiveID=id; }

    void generateReport() {
        printLine();
        cout << "  [CLOSED CASE]\n";
        cout << "  Case ID         : " << caseID << "\n";
        cout << "  Title           : " << title << "\n";
        cout << "  Date Opened     : " << date << "\n";
        cout << "  Date Closed     : " << closingDate << "\n";
        cout << "  Description     : " << description << "\n";
        cout << "  Linked Criminal : " << linkedCriminalID << "\n";
        cout << "  Detective       : " << assignedDetectiveID << "\n";
        cout << "  Verdict         : " << verdict << "\n";
        cout << "  Status          : " << status << "\n";
        printLine();
    }
};

// ============================================================
//   EVIDENCE CLASS
// ============================================================

class Evidence {
private:
    string evidenceID;
    string type;
    string description;
    string linkedCaseID;
    string linkedCriminalID;
public:
    Evidence() { evidenceID=""; type=""; description=""; linkedCaseID=""; linkedCriminalID=""; }
    Evidence(string id, string t, string desc, string cid, string crimid)
        { evidenceID=id; type=t; description=desc; linkedCaseID=cid; linkedCriminalID=crimid; }

    string getEvidenceID()           { return evidenceID; }
    void setEvidenceID(string id)    { evidenceID=id; }
    string getType()                 { return type; }
    void setType(string t)           { type=t; }
    string getDescription()          { return description; }
    void setDescription(string d)    { description=d; }
    string getLinkedCaseID()         { return linkedCaseID; }
    void setLinkedCaseID(string id)  { linkedCaseID=id; }
    string getLinkedCriminalID()     { return linkedCriminalID; }
    void setLinkedCriminalID(string id){ linkedCriminalID=id; }

    void display() {
        printLine();
        cout << "  Evidence ID     : " << evidenceID << "\n";
        cout << "  Type            : " << type << "\n";
        cout << "  Description     : " << description << "\n";
        cout << "  Linked Case     : " << linkedCaseID << "\n";
        cout << "  Linked Criminal : " << linkedCriminalID << "\n";
        printLine();
    }
};

// ============================================================
//   ARREST CLASS
// ============================================================

class Arrest {
private:
    string arrestID;
    string criminalID;
    string criminalName;
    string arrestDate;
    string arrestingOfficer;
    string location;
public:
    Arrest() { arrestID=""; criminalID=""; criminalName=""; arrestDate=""; arrestingOfficer=""; location=""; }
    Arrest(string id, string cid, string cname, string d, string officer, string loc)
        { arrestID=id; criminalID=cid; criminalName=cname; arrestDate=d; arrestingOfficer=officer; location=loc; }

    string getArrestID()             { return arrestID; }
    void setArrestID(string id)      { arrestID=id; }
    string getCriminalID()           { return criminalID; }
    void setCriminalID(string id)    { criminalID=id; }
    string getCriminalName()         { return criminalName; }
    void setCriminalName(string n)   { criminalName=n; }
    string getArrestDate()           { return arrestDate; }
    void setArrestDate(string d)     { arrestDate=d; }
    string getArrestingOfficer()     { return arrestingOfficer; }
    void setArrestingOfficer(string o){ arrestingOfficer=o; }
    string getLocation()             { return location; }
    void setLocation(string l)       { location=l; }

    void display() {
        printLine();
        cout << "  Arrest ID       : " << arrestID << "\n";
        cout << "  Criminal ID     : " << criminalID << "\n";
        cout << "  Criminal Name   : " << criminalName << "\n";
        cout << "  Arrest Date     : " << arrestDate << "\n";
        cout << "  Officer         : " << arrestingOfficer << "\n";
        cout << "  Location        : " << location << "\n";
        printLine();
    }
};

// ============================================================
//   BAIL CLASS
// ============================================================

class Bail {
private:
    string bailID;
    string criminalID;
    string criminalName;
    string amount;
    string bailDate;
    string approvedBy;
public:
    Bail() { bailID=""; criminalID=""; criminalName=""; amount=""; bailDate=""; approvedBy="Admin"; }
    Bail(string id, string cid, string cname, string amt, string d, string approved)
        { bailID=id; criminalID=cid; criminalName=cname; amount=amt; bailDate=d; approvedBy=approved; }

    string getBailID()               { return bailID; }
    void setBailID(string id)        { bailID=id; }
    string getCriminalID()           { return criminalID; }
    void setCriminalID(string id)    { criminalID=id; }
    string getCriminalName()         { return criminalName; }
    void setCriminalName(string n)   { criminalName=n; }
    string getAmount()               { return amount; }
    void setAmount(string a)         { amount=a; }
    string getBailDate()             { return bailDate; }
    void setBailDate(string d)       { bailDate=d; }
    string getApprovedBy()           { return approvedBy; }
    void setApprovedBy(string a)     { approvedBy=a; }

    void display() {
        printLine();
        cout << "  Bail ID         : " << bailID << "\n";
        cout << "  Criminal ID     : " << criminalID << "\n";
        cout << "  Criminal Name   : " << criminalName << "\n";
        cout << "  Amount (PKR)    : " << amount << "\n";
        cout << "  Date            : " << bailDate << "\n";
        cout << "  Approved By     : " << approvedBy << "\n";
        printLine();
    }
};

// ============================================================
//   CRIME SCENE CLASS
// ============================================================

class CrimeScene {
private:
    string sceneID;
    string location;
    string sceneDate;
    string crimeType;
    string description;
    string linkedCaseID;
public:
    CrimeScene() { sceneID=""; location=""; sceneDate=""; crimeType=""; description=""; linkedCaseID=""; }
    CrimeScene(string id, string loc, string d, string type, string desc, string cid)
        { sceneID=id; location=loc; sceneDate=d; crimeType=type; description=desc; linkedCaseID=cid; }

    string getSceneID()              { return sceneID; }
    void setSceneID(string id)       { sceneID=id; }
    string getLocation()             { return location; }
    void setLocation(string l)       { location=l; }
    string getSceneDate()            { return sceneDate; }
    void setSceneDate(string d)      { sceneDate=d; }
    string getCrimeType()            { return crimeType; }
    void setCrimeType(string t)      { crimeType=t; }
    string getDescription()          { return description; }
    void setDescription(string d)    { description=d; }
    string getLinkedCaseID()         { return linkedCaseID; }
    void setLinkedCaseID(string id)  { linkedCaseID=id; }

    void display() {
        printLine();
        cout << "  Scene ID        : " << sceneID << "\n";
        cout << "  Location        : " << location << "\n";
        cout << "  Date            : " << sceneDate << "\n";
        cout << "  Crime Type      : " << crimeType << "\n";
        cout << "  Description     : " << description << "\n";
        cout << "  Linked Case     : " << linkedCaseID << "\n";
        printLine();
    }
};

// ============================================================
//   COURT HEARING CLASS
// ============================================================

class CourtHearing {
private:
    string hearingID;
    string caseID;
    string hearingDate;
    string judgeName;
    string verdict;
public:
    CourtHearing() { hearingID=""; caseID=""; hearingDate=""; judgeName=""; verdict="Pending"; }
    CourtHearing(string id, string cid, string d, string judge, string verd)
        { hearingID=id; caseID=cid; hearingDate=d; judgeName=judge; verdict=verd; }

    string getHearingID()            { return hearingID; }
    void setHearingID(string id)     { hearingID=id; }
    string getCaseID()               { return caseID; }
    void setCaseID(string id)        { caseID=id; }
    string getHearingDate()          { return hearingDate; }
    void setHearingDate(string d)    { hearingDate=d; }
    string getJudgeName()            { return judgeName; }
    void setJudgeName(string j)      { judgeName=j; }
    string getVerdict()              { return verdict; }
    void setVerdict(string v)        { verdict=v; }

    void display() {
        printLine();
        cout << "  Hearing ID      : " << hearingID << "\n";
        cout << "  Case ID         : " << caseID << "\n";
        cout << "  Hearing Date    : " << hearingDate << "\n";
        cout << "  Judge           : " << judgeName << "\n";
        cout << "  Verdict         : " << verdict << "\n";
        printLine();
    }
};

// ============================================================
//   NOTIFICATION CLASS
// ============================================================

class Notification {
private:
    string notifID;
    string message;
    string criminalID;
    string criminalName;
    string notifType;
    string notifDate;
public:
    Notification() { notifID=""; message=""; criminalID=""; criminalName=""; notifType=""; notifDate=""; }
    Notification(string id, string msg, string cid, string cname, string type, string d)
        { notifID=id; message=msg; criminalID=cid; criminalName=cname; notifType=type; notifDate=d; }

    string getNotifID()              { return notifID; }
    void setNotifID(string id)       { notifID=id; }
    string getMessage()              { return message; }
    void setMessage(string m)        { message=m; }
    string getCriminalID()           { return criminalID; }
    void setCriminalID(string id)    { criminalID=id; }
    string getCriminalName()         { return criminalName; }
    void setCriminalName(string n)   { criminalName=n; }
    string getNotifType()            { return notifType; }
    void setNotifType(string t)      { notifType=t; }
    string getNotifDate()            { return notifDate; }
    void setNotifDate(string d)      { notifDate=d; }

    void display() {
        printLine();
        cout << "  [!] ALERT - " << notifType << "\n";
        cout << "  " << message << "\n";
        cout << "  Criminal : " << criminalName << " [" << criminalID << "]\n";
        cout << "  Date     : " << notifDate << "\n";
        printLine();
    }
};

// ============================================================
//   MEETING CLASS
// ============================================================

class Meeting {
private:
    string meetingID;
    string personUsername;
    string personType;
    string meetingDate;
    string meetingTime;
public:
    Meeting() { meetingID=""; personUsername=""; personType=""; meetingDate=""; meetingTime=""; }
    Meeting(string id, string user, string type, string d, string t)
        { meetingID=id; personUsername=user; personType=type; meetingDate=d; meetingTime=t; }

    string getMeetingID()            { return meetingID; }
    void setMeetingID(string id)     { meetingID=id; }
    string getPersonUsername()       { return personUsername; }
    void setPersonUsername(string u) { personUsername=u; }
    string getPersonType()           { return personType; }
    void setPersonType(string t)     { personType=t; }
    string getMeetingDate()          { return meetingDate; }
    void setMeetingDate(string d)    { meetingDate=d; }
    string getMeetingTime()          { return meetingTime; }
    void setMeetingTime(string t)    { meetingTime=t; }

    void display() {
        printLine();
        cout << "  Meeting ID      : " << meetingID << "\n";
        cout << "  With            : " << personUsername << " (" << personType << ")\n";
        cout << "  Date            : " << meetingDate << "\n";
        cout << "  Time            : " << meetingTime << "\n";
        printLine();
    }
};

// ============================================================
//   GLOBAL DATA VECTORS
// ============================================================

vector<Criminal>     criminals;
vector<Officer>      officers;
vector<Detective>    detectives;
vector<ActiveCase>   activeCases;
vector<ClosedCase>   closedCases;
vector<Evidence>     evidences;
vector<Arrest>       arrests;
vector<Bail>         bails;
vector<CrimeScene>   crimeScenes;
vector<CourtHearing> courtHearings;
vector<Witness>      witnesses;
vector<Victim>       victims;
vector<Notification> notifications;
vector<Meeting>      meetings;

// ============================================================
//   FILE HANDLER - SAVE FUNCTIONS
// ============================================================

void saveCriminals() {
    ofstream f("criminals.txt");
    for (int i = 0; i < (int)criminals.size(); i++) {
        f << criminals[i].getCriminalID() << "|"
          << criminals[i].getName() << "|"
          << criminals[i].getAge() << "|"
          << criminals[i].getCnic() << "|"
          << criminals[i].getAddress() << "|"
          << criminals[i].getCrimeType() << "|"
          << criminals[i].getThreatLvl() << "|"
          << criminals[i].getBailStatus() << "\n";
    }
    f.close();
}

void saveOfficers() {
    ofstream f("officers.txt");
    for (int i = 0; i < (int)officers.size(); i++) {
        f << officers[i].getOfficerID() << "|"
          << officers[i].getName() << "|"
          << officers[i].getAge() << "|"
          << officers[i].getCnic() << "|"
          << officers[i].getAddress() << "|"
          << officers[i].getUsername() << "|"
          << officers[i].getPassword() << "|"
          << officers[i].getBadgeNo() << "|"
          << officers[i].getDepartment() << "|"
          << officers[i].getRank() << "\n";
    }
    f.close();
}

void saveDetectives() {
    ofstream f("detectives.txt");
    for (int i = 0; i < (int)detectives.size(); i++) {
        f << detectives[i].getDetectiveID() << "|"
          << detectives[i].getName() << "|"
          << detectives[i].getAge() << "|"
          << detectives[i].getCnic() << "|"
          << detectives[i].getAddress() << "|"
          << detectives[i].getUsername() << "|"
          << detectives[i].getPassword() << "|"
          << detectives[i].getSpecialization() << "|"
          << detectives[i].getCaseLoad() << "\n";
    }
    f.close();
}

void saveActiveCases() {
    ofstream f("active_cases.txt");
    for (int i = 0; i < (int)activeCases.size(); i++) {
        f << activeCases[i].getCaseID() << "|"
          << activeCases[i].getTitle() << "|"
          << activeCases[i].getDate() << "|"
          << activeCases[i].getDescription() << "|"
          << activeCases[i].getLinkedCriminalID() << "|"
          << activeCases[i].getAssignedDetectiveID() << "|"
          << activeCases[i].getProgress() << "\n";
    }
    f.close();
}

void saveClosedCases() {
    ofstream f("closed_cases.txt");
    for (int i = 0; i < (int)closedCases.size(); i++) {
        f << closedCases[i].getCaseID() << "|"
          << closedCases[i].getTitle() << "|"
          << closedCases[i].getDate() << "|"
          << closedCases[i].getDescription() << "|"
          << closedCases[i].getLinkedCriminalID() << "|"
          << closedCases[i].getVerdict() << "|"
          << closedCases[i].getClosingDate() << "|"
          << closedCases[i].getAssignedDetectiveID() << "\n";
    }
    f.close();
}

void saveEvidence() {
    ofstream f("evidence.txt");
    for (int i = 0; i < (int)evidences.size(); i++) {
        f << evidences[i].getEvidenceID() << "|"
          << evidences[i].getType() << "|"
          << evidences[i].getDescription() << "|"
          << evidences[i].getLinkedCaseID() << "|"
          << evidences[i].getLinkedCriminalID() << "\n";
    }
    f.close();
}

void saveArrests() {
    ofstream f("arrests.txt");
    for (int i = 0; i < (int)arrests.size(); i++) {
        f << arrests[i].getArrestID() << "|"
          << arrests[i].getCriminalID() << "|"
          << arrests[i].getCriminalName() << "|"
          << arrests[i].getArrestDate() << "|"
          << arrests[i].getArrestingOfficer() << "|"
          << arrests[i].getLocation() << "\n";
    }
    f.close();
}

void saveBails() {
    ofstream f("bail.txt");
    for (int i = 0; i < (int)bails.size(); i++) {
        f << bails[i].getBailID() << "|"
          << bails[i].getCriminalID() << "|"
          << bails[i].getCriminalName() << "|"
          << bails[i].getAmount() << "|"
          << bails[i].getBailDate() << "|"
          << bails[i].getApprovedBy() << "\n";
    }
    f.close();
}

void saveCrimeScenes() {
    ofstream f("crime_scenes.txt");
    for (int i = 0; i < (int)crimeScenes.size(); i++) {
        f << crimeScenes[i].getSceneID() << "|"
          << crimeScenes[i].getLocation() << "|"
          << crimeScenes[i].getSceneDate() << "|"
          << crimeScenes[i].getCrimeType() << "|"
          << crimeScenes[i].getDescription() << "|"
          << crimeScenes[i].getLinkedCaseID() << "\n";
    }
    f.close();
}

void saveCourtHearings() {
    ofstream f("court_hearings.txt");
    for (int i = 0; i < (int)courtHearings.size(); i++) {
        f << courtHearings[i].getHearingID() << "|"
          << courtHearings[i].getCaseID() << "|"
          << courtHearings[i].getHearingDate() << "|"
          << courtHearings[i].getJudgeName() << "|"
          << courtHearings[i].getVerdict() << "\n";
    }
    f.close();
}

void saveWitnesses() {
    ofstream f("witnesses.txt");
    for (int i = 0; i < (int)witnesses.size(); i++) {
        f << witnesses[i].getWitnessID() << "|"
          << witnesses[i].getName() << "|"
          << witnesses[i].getAge() << "|"
          << witnesses[i].getCnic() << "|"
          << witnesses[i].getAddress() << "|"
          << witnesses[i].getStatement() << "|"
          << witnesses[i].getProtectionStatus() << "|"
          << witnesses[i].getLinkedCaseID() << "|"
          << witnesses[i].getLinkedCriminalID() << "\n";
    }
    f.close();
}

void saveVictims() {
    ofstream f("victims.txt");
    for (int i = 0; i < (int)victims.size(); i++) {
        f << victims[i].getVictimID() << "|"
          << victims[i].getName() << "|"
          << victims[i].getAge() << "|"
          << victims[i].getCnic() << "|"
          << victims[i].getAddress() << "|"
          << victims[i].getInjuryLevel() << "|"
          << victims[i].getLinkedCaseID() << "|"
          << victims[i].getLinkedCriminalID() << "\n";
    }
    f.close();
}

void saveNotifications() {
    ofstream f("notifications.txt");
    for (int i = 0; i < (int)notifications.size(); i++) {
        f << notifications[i].getNotifID() << "|"
          << notifications[i].getMessage() << "|"
          << notifications[i].getCriminalID() << "|"
          << notifications[i].getCriminalName() << "|"
          << notifications[i].getNotifType() << "|"
          << notifications[i].getNotifDate() << "\n";
    }
    f.close();
}

void saveMeetings() {
    ofstream f("meetings.txt");
    for (int i = 0; i < (int)meetings.size(); i++) {
        f << meetings[i].getMeetingID() << "|"
          << meetings[i].getPersonUsername() << "|"
          << meetings[i].getPersonType() << "|"
          << meetings[i].getMeetingDate() << "|"
          << meetings[i].getMeetingTime() << "\n";
    }
    f.close();
}

// ============================================================
//   FILE HANDLER - LOAD FUNCTIONS
// ============================================================

void loadCriminals() {
    ifstream f("criminals.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, ageS, cnic, addr, crime, threat, bail;
        getline(ss, id,     '|');
        getline(ss, name,   '|');
        getline(ss, ageS,   '|');
        getline(ss, cnic,   '|');
        getline(ss, addr,   '|');
        getline(ss, crime,  '|');
        getline(ss, threat, '|');
        getline(ss, bail,   '|');
        Criminal c(id, name, atoi(ageS.c_str()), cnic, addr, crime, threat);
        c.setBailStatus(bail);
        criminals.push_back(c);
        criminalCount++;
    }
    f.close();
}

void loadOfficers() {
    ifstream f("officers.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, ageS, cnic, addr, user, pass, badge, dept, rank;
        getline(ss, id,    '|');
        getline(ss, name,  '|');
        getline(ss, ageS,  '|');
        getline(ss, cnic,  '|');
        getline(ss, addr,  '|');
        getline(ss, user,  '|');
        getline(ss, pass,  '|');
        getline(ss, badge, '|');
        getline(ss, dept,  '|');
        getline(ss, rank,  '|');
        Officer o(id, name, atoi(ageS.c_str()), cnic, addr, user, pass, badge, dept, rank);
        officers.push_back(o);
        officerCount++;
    }
    f.close();
}

void loadDetectives() {
    ifstream f("detectives.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, ageS, cnic, addr, user, pass, spec, clS;
        getline(ss, id,   '|');
        getline(ss, name, '|');
        getline(ss, ageS, '|');
        getline(ss, cnic, '|');
        getline(ss, addr, '|');
        getline(ss, user, '|');
        getline(ss, pass, '|');
        getline(ss, spec, '|');
        getline(ss, clS,  '|');
        Detective d(id, name, atoi(ageS.c_str()), cnic, addr, user, pass, spec);
        d.setCaseLoad(atoi(clS.c_str()));
        detectives.push_back(d);
        detectiveCount++;
    }
    f.close();
}

void loadActiveCases() {
    ifstream f("active_cases.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, title, date, desc, cid, detID, prog;
        getline(ss, id,    '|');
        getline(ss, title, '|');
        getline(ss, date,  '|');
        getline(ss, desc,  '|');
        getline(ss, cid,   '|');
        getline(ss, detID, '|');
        getline(ss, prog,  '|');
        ActiveCase ac(id, title, date, desc, cid);
        ac.setAssignedDetectiveID(detID);
        ac.setProgress(prog);
        activeCases.push_back(ac);
        caseCount++;
    }
    f.close();
}

void loadClosedCases() {
    ifstream f("closed_cases.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, title, date, desc, cid, verd, closeDate, detID;
        getline(ss, id,        '|');
        getline(ss, title,     '|');
        getline(ss, date,      '|');
        getline(ss, desc,      '|');
        getline(ss, cid,       '|');
        getline(ss, verd,      '|');
        getline(ss, closeDate, '|');
        getline(ss, detID,     '|');
        ClosedCase cc(id, title, date, desc, cid, verd, closeDate, detID);
        closedCases.push_back(cc);
    }
    f.close();
}

void loadEvidence() {
    ifstream f("evidence.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, type, desc, cid, crimid;
        getline(ss, id,     '|');
        getline(ss, type,   '|');
        getline(ss, desc,   '|');
        getline(ss, cid,    '|');
        getline(ss, crimid, '|');
        Evidence e(id, type, desc, cid, crimid);
        evidences.push_back(e);
        evidenceCount++;
    }
    f.close();
}

void loadArrests() {
    ifstream f("arrests.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, cid, cname, date, officer, loc;
        getline(ss, id,      '|');
        getline(ss, cid,     '|');
        getline(ss, cname,   '|');
        getline(ss, date,    '|');
        getline(ss, officer, '|');
        getline(ss, loc,     '|');
        Arrest a(id, cid, cname, date, officer, loc);
        arrests.push_back(a);
        arrestCount++;
    }
    f.close();
}

void loadBails() {
    ifstream f("bail.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, cid, cname, amt, date, approved;
        getline(ss, id,       '|');
        getline(ss, cid,      '|');
        getline(ss, cname,    '|');
        getline(ss, amt,      '|');
        getline(ss, date,     '|');
        getline(ss, approved, '|');
        Bail b(id, cid, cname, amt, date, approved);
        bails.push_back(b);
        bailCount++;
    }
    f.close();
}

void loadCrimeScenes() {
    ifstream f("crime_scenes.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, loc, date, type, desc, cid;
        getline(ss, id,   '|');
        getline(ss, loc,  '|');
        getline(ss, date, '|');
        getline(ss, type, '|');
        getline(ss, desc, '|');
        getline(ss, cid,  '|');
        CrimeScene cs(id, loc, date, type, desc, cid);
        crimeScenes.push_back(cs);
        sceneCount++;
    }
    f.close();
}

void loadCourtHearings() {
    ifstream f("court_hearings.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, cid, date, judge, verd;
        getline(ss, id,    '|');
        getline(ss, cid,   '|');
        getline(ss, date,  '|');
        getline(ss, judge, '|');
        getline(ss, verd,  '|');
        CourtHearing ch(id, cid, date, judge, verd);
        courtHearings.push_back(ch);
        hearingCount++;
    }
    f.close();
}

void loadWitnesses() {
    ifstream f("witnesses.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, ageS, cnic, addr, stmt, prot, cid, crimid;
        getline(ss, id,     '|');
        getline(ss, name,   '|');
        getline(ss, ageS,   '|');
        getline(ss, cnic,   '|');
        getline(ss, addr,   '|');
        getline(ss, stmt,   '|');
        getline(ss, prot,   '|');
        getline(ss, cid,    '|');
        getline(ss, crimid, '|');
        Witness w(id, name, atoi(ageS.c_str()), cnic, addr, stmt, prot, cid, crimid);
        witnesses.push_back(w);
        witnessCount++;
    }
    f.close();
}

void loadVictims() {
    ifstream f("victims.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, ageS, cnic, addr, injury, cid, crimid;
        getline(ss, id,     '|');
        getline(ss, name,   '|');
        getline(ss, ageS,   '|');
        getline(ss, cnic,   '|');
        getline(ss, addr,   '|');
        getline(ss, injury, '|');
        getline(ss, cid,    '|');
        getline(ss, crimid, '|');
        Victim v(id, name, atoi(ageS.c_str()), cnic, addr, injury, cid, crimid);
        victims.push_back(v);
        victimCount++;
    }
    f.close();
}

void loadNotifications() {
    ifstream f("notifications.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, msg, cid, cname, type, date;
        getline(ss, id,    '|');
        getline(ss, msg,   '|');
        getline(ss, cid,   '|');
        getline(ss, cname, '|');
        getline(ss, type,  '|');
        getline(ss, date,  '|');
        Notification n(id, msg, cid, cname, type, date);
        notifications.push_back(n);
        notifCount++;
    }
    f.close();
}

void loadMeetings() {
    ifstream f("meetings.txt");
    if (!f.is_open()) return;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, user, type, date, mtime;
        getline(ss, id,    '|');
        getline(ss, user,  '|');
        getline(ss, type,  '|');
        getline(ss, date,  '|');
        getline(ss, mtime, '|');
        Meeting m(id, user, type, date, mtime);
        meetings.push_back(m);
        meetingCount++;
    }
    f.close();
}

void loadAllData() {
    loadCriminals();
    loadOfficers();
    loadDetectives();
    loadActiveCases();
    loadClosedCases();
    loadEvidence();
    loadArrests();
    loadBails();
    loadCrimeScenes();
    loadCourtHearings();
    loadWitnesses();
    loadVictims();
    loadNotifications();
    loadMeetings();
}

// ============================================================
//   HELPER - FIND FUNCTIONS
// ============================================================

int findCriminal(string id) {
    for (int i = 0; i < (int)criminals.size(); i++)
        if (criminals[i].getCriminalID() == id) return i;
    return -1;
}

int findActiveCase(string id) {
    for (int i = 0; i < (int)activeCases.size(); i++)
        if (activeCases[i].getCaseID() == id) return i;
    return -1;
}

int findDetective(string username) {
    for (int i = 0; i < (int)detectives.size(); i++)
        if (detectives[i].getUsername() == username) return i;
    return -1;
}

// ============================================================
//   OFFICER MENU FUNCTIONS
// ============================================================

void addCriminal(string officerName) {
    cout << "\n  === ADD CRIMINAL ===\n";
    string name    = getValidString("  Name          : ");
    int age        = getValidInt("  Age           : ");
    string cnic    = getAnyString("  CNIC          : ");
    string address = getAnyString("  Address       : ");
    string crime   = getAnyString("  Crime Type    : ");
    string threat  = getThreatLevel();
    string id      = genCriminalID();

    Criminal c(id, name, age, cnic, address, crime, threat);
    criminals.push_back(c);
    saveCriminals();

    cout << "\n  [+] Criminal added! ID: " << id << "\n";

    if (threat == "MOST WANTED") {
        string nid = genNotifID();
        string msg = "ALERT: " + name + " is MOST WANTED - " + crime;
        Notification n(nid, msg, id, name, "MOST WANTED", "2025-06-25");
        notifications.push_back(n);
        saveNotifications();
        cout << "\n  [!] ALERT GENERATED: " << name << " is MOST WANTED!\n";
    }

    cout << "\n  Add a case for this criminal? (Y/N): ";
    string ch; getline(cin, ch);
    if (toUpper(ch) == "Y") {
        string caseID  = genCaseID();
        string title   = getAnyString("  Case Title    : ");
        string date    = getAnyString("  Case Date     : ");
        string desc    = getAnyString("  Description   : ");
        ActiveCase ac(caseID, title, date, desc, id);
        activeCases.push_back(ac);
        saveActiveCases();
        cout << "\n  [+] Case added! ID: " << caseID << "\n";
    }
    pressEnter();
}

void viewAllCriminals() {
    cout << "\n  === ALL CRIMINALS ===\n";
    if (criminals.empty()) { cout << "  No criminals found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)criminals.size(); i++)
        criminals[i].getDetails();
    pressEnter();
}

void updateCriminal() {
    cout << "\n  === UPDATE CRIMINAL ===\n";
    string id = getAnyString("  Enter Criminal ID: ");
    int idx = findCriminal(id);
    if (idx == -1) { cout << "  [!] Criminal not found.\n"; pressEnter(); return; }
    criminals[idx].getDetails();
    cout << "  What to update?\n";
    cout << "  1. Name\n  2. Age\n  3. Address\n  4. Crime Type\n  5. Threat Level\n";
    int ch = getValidInt("  Choice: ");
    if (ch == 1) criminals[idx].setName(getValidString("  New Name: "));
    else if (ch == 2) criminals[idx].setAge(getValidInt("  New Age: "));
    else if (ch == 3) criminals[idx].setAddress(getAnyString("  New Address: "));
    else if (ch == 4) criminals[idx].setCrimeType(getAnyString("  New Crime Type: "));
    else if (ch == 5) {
        string t = getThreatLevel();
        criminals[idx].setThreatLvl(t);
        if (t == "MOST WANTED") {
            string nid = genNotifID();
            string msg = "ALERT: " + criminals[idx].getName() + " updated to MOST WANTED!";
            Notification n(nid, msg, id, criminals[idx].getName(), "MOST WANTED", "2025-06-25");
            notifications.push_back(n);
            saveNotifications();
            cout << "\n  [!] ALERT: " << criminals[idx].getName() << " is now MOST WANTED!\n";
        }
    }
    saveCriminals();
    cout << "\n  [+] Criminal updated!\n";
    pressEnter();
}

void deleteCriminal() {
    cout << "\n  === DELETE CRIMINAL ===\n";
    string id = getAnyString("  Enter Criminal ID to delete: ");
    int idx = findCriminal(id);
    if (idx == -1) { cout << "  [!] Criminal not found.\n"; pressEnter(); return; }
    cout << "  Deleting: " << criminals[idx].getName() << "\n";
    criminals.erase(criminals.begin() + idx);
    saveCriminals();

    // Delete linked active cases
    for (int i = (int)activeCases.size()-1; i >= 0; i--) {
        if (activeCases[i].getLinkedCriminalID() == id) {
            activeCases.erase(activeCases.begin() + i);
        }
    }
    saveActiveCases();

    cout << "\n  [+] Criminal and linked cases deleted. Stats updated.\n";
    pressEnter();
}

void addCase() {
    cout << "\n  === ADD CASE ===\n";
    if (criminals.empty()) { cout << "  [!] No criminals found. Add a criminal first.\n"; pressEnter(); return; }
    string crimID = getAnyString("  Enter Criminal ID to link case: ");
    int idx = findCriminal(crimID);
    if (idx == -1) { cout << "  [!] Criminal not found.\n"; pressEnter(); return; }
    string caseID = genCaseID();
    string title  = getAnyString("  Case Title  : ");
    string date   = getAnyString("  Case Date   : ");
    string desc   = getAnyString("  Description : ");
    ActiveCase ac(caseID, title, date, desc, crimID);
    activeCases.push_back(ac);
    saveActiveCases();
    cout << "\n  [+] Case added! ID: " << caseID << "\n";
    pressEnter();
}

void viewActiveCases() {
    cout << "\n  === ACTIVE CASES ===\n";
    if (activeCases.empty()) { cout << "  No active cases.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)activeCases.size(); i++)
        activeCases[i].generateReport();
    pressEnter();
}

void viewClosedCases() {
    cout << "\n  === CLOSED CASES ===\n";
    if (closedCases.empty()) { cout << "  No closed cases.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)closedCases.size(); i++)
        closedCases[i].generateReport();
    pressEnter();
}

void updateCase() {
    cout << "\n  === UPDATE CASE ===\n";
    string id = getAnyString("  Enter Case ID: ");
    int idx = findActiveCase(id);
    if (idx == -1) { cout << "  [!] Active case not found.\n"; pressEnter(); return; }
    cout << "  1. Title\n  2. Description\n  3. Progress\n";
    int ch = getValidInt("  Choice: ");
    if (ch == 1) activeCases[idx].setTitle(getAnyString("  New Title: "));
    else if (ch == 2) activeCases[idx].setDescription(getAnyString("  New Description: "));
    else if (ch == 3) activeCases[idx].setProgress(getAnyString("  New Progress: "));
    saveActiveCases();
    cout << "\n  [+] Case updated!\n";
    pressEnter();
}

void addEvidence(string officerName) {
    cout << "\n  === ADD EVIDENCE ===\n";
    string caseID  = getAnyString("  Linked Case ID    : ");
    string crimID  = getAnyString("  Linked Criminal ID: ");
    string type    = getAnyString("  Evidence Type     : ");
    string desc    = getAnyString("  Description       : ");
    string id      = genEvidenceID();
    Evidence e(id, type, desc, caseID, crimID);
    evidences.push_back(e);
    saveEvidence();
    cout << "\n  [+] Evidence added! ID: " << id << "\n";
    pressEnter();
}

void viewEvidence() {
    cout << "\n  === ALL EVIDENCE ===\n";
    if (evidences.empty()) { cout << "  No evidence found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)evidences.size(); i++)
        evidences[i].display();
    pressEnter();
}

void addWitness() {
    cout << "\n  === ADD WITNESS ===\n";
    string caseID  = getAnyString("  Linked Case ID    : ");
    string crimID  = getAnyString("  Linked Criminal ID: ");
    string name    = getValidString("  Witness Name      : ");
    int age        = getValidInt("  Age               : ");
    string cnic    = getAnyString("  CNIC              : ");
    string addr    = getAnyString("  Address           : ");
    string stmt    = getAnyString("  Statement         : ");
    string prot    = getAnyString("  Protection Status : ");
    string id      = genWitnessID();
    Witness w(id, name, age, cnic, addr, stmt, prot, caseID, crimID);
    witnesses.push_back(w);
    saveWitnesses();
    cout << "\n  [+] Witness added! ID: " << id << "\n";
    pressEnter();
}

void viewWitnesses() {
    cout << "\n  === ALL WITNESSES ===\n";
    if (witnesses.empty()) { cout << "  No witnesses found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)witnesses.size(); i++)
        witnesses[i].getDetails();
    pressEnter();
}

void addVictim() {
    cout << "\n  === ADD VICTIM ===\n";
    string caseID  = getAnyString("  Linked Case ID    : ");
    string crimID  = getAnyString("  Linked Criminal ID: ");
    string name    = getValidString("  Victim Name       : ");
    int age        = getValidInt("  Age               : ");
    string cnic    = getAnyString("  CNIC              : ");
    string addr    = getAnyString("  Address           : ");
    string injury  = getAnyString("  Injury Level      : ");
    string id      = genVictimID();
    Victim v(id, name, age, cnic, addr, injury, caseID, crimID);
    victims.push_back(v);
    saveVictims();
    cout << "\n  [+] Victim added! ID: " << id << "\n";
    pressEnter();
}

void viewVictims() {
    cout << "\n  === ALL VICTIMS ===\n";
    if (victims.empty()) { cout << "  No victims found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)victims.size(); i++)
        victims[i].getDetails();
    pressEnter();
}

void addArrest(string officerName) {
    cout << "\n  === ADD ARREST ===\n";
    string crimID  = getAnyString("  Criminal ID  : ");
    int idx = findCriminal(crimID);
    if (idx == -1) { cout << "  [!] Criminal not found.\n"; pressEnter(); return; }
    string date    = getAnyString("  Arrest Date  : ");
    string loc     = getAnyString("  Location     : ");
    string id      = genArrestID();
    Arrest a(id, crimID, criminals[idx].getName(), date, officerName, loc);
    arrests.push_back(a);
    saveArrests();
    cout << "\n  [+] Arrest recorded! ID: " << id << "\n";
    pressEnter();
}

void viewArrests() {
    cout << "\n  === ALL ARRESTS ===\n";
    if (arrests.empty()) { cout << "  No arrests found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)arrests.size(); i++)
        arrests[i].display();
    pressEnter();
}

void addCrimeScene() {
    cout << "\n  === ADD CRIME SCENE ===\n";
    string caseID  = getAnyString("  Linked Case ID: ");
    string loc     = getAnyString("  Location      : ");
    string date    = getAnyString("  Date          : ");
    string type    = getAnyString("  Crime Type    : ");
    string desc    = getAnyString("  Description   : ");
    string id      = genSceneID();
    CrimeScene cs(id, loc, date, type, desc, caseID);
    crimeScenes.push_back(cs);
    saveCrimeScenes();
    cout << "\n  [+] Crime Scene added! ID: " << id << "\n";
    pressEnter();
}

void viewCrimeScenes() {
    cout << "\n  === ALL CRIME SCENES ===\n";
    if (crimeScenes.empty()) { cout << "  No crime scenes found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)crimeScenes.size(); i++)
        crimeScenes[i].display();
    pressEnter();
}

void addCourtHearing() {
    cout << "\n  === ADD COURT HEARING ===\n";
    string caseID  = getAnyString("  Case ID      : ");
    string date    = getAnyString("  Hearing Date : ");
    string judge   = getValidString("  Judge Name   : ");
    string verdict = getAnyString("  Verdict      : ");
    string id      = genHearingID();
    CourtHearing ch(id, caseID, date, judge, verdict);
    courtHearings.push_back(ch);
    saveCourtHearings();
    cout << "\n  [+] Court Hearing added! ID: " << id << "\n";
    pressEnter();
}

void viewCourtHearings() {
    cout << "\n  === ALL COURT HEARINGS ===\n";
    if (courtHearings.empty()) { cout << "  No court hearings found.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)courtHearings.size(); i++)
        courtHearings[i].display();
    pressEnter();
}

void searchAndFilter() {
    cout << "\n  === SEARCH & FILTER ===\n";
    cout << "  1. Search by Name\n";
    cout << "  2. Search by Criminal ID\n";
    cout << "  3. Filter by Threat Level\n";
    cout << "  4. Filter by Crime Type\n";
    int ch = getValidInt("  Choice: ");
    bool found = false;

    if (ch == 1) {
        string name = getAnyString("  Enter Name: ");
        for (int i = 0; i < (int)criminals.size(); i++) {
            if (toUpper(criminals[i].getName()).find(toUpper(name)) != string::npos) {
                criminals[i].getDetails(); found = true;
            }
        }
    } else if (ch == 2) {
        string id = getAnyString("  Enter Criminal ID: ");
        int idx = findCriminal(id);
        if (idx != -1) { criminals[idx].getDetails(); found = true; }
    } else if (ch == 3) {
        string threat = getThreatLevel();
        for (int i = 0; i < (int)criminals.size(); i++) {
            if (toUpper(criminals[i].getThreatLvl()) == toUpper(threat)) {
                criminals[i].getDetails(); found = true;
            }
        }
    } else if (ch == 4) {
        string crime = getAnyString("  Enter Crime Type: ");
        for (int i = 0; i < (int)criminals.size(); i++) {
            if (toUpper(criminals[i].getCrimeType()).find(toUpper(crime)) != string::npos) {
                criminals[i].getDetails(); found = true;
            }
        }
    }

    if (!found) cout << "  [!] No records found.\n";
    pressEnter();
}

void viewNotifications() {
    cout << "\n  === NOTIFICATIONS / ALERTS ===\n";
    if (notifications.empty()) { cout << "  No notifications.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)notifications.size(); i++)
        notifications[i].display();
    pressEnter();
}

void generateReport() {
    cout << "\n  === GENERATE CRIMINAL REPORT ===\n";
    string id = getAnyString("  Enter Criminal ID: ");
    int idx = findCriminal(id);
    if (idx == -1) { cout << "  [!] Criminal not found.\n"; pressEnter(); return; }

    int evCount = 0, wiCount = 0, viCount = 0;
    string caseStatus = "No Case", verdict = "N/A", caseIDFound = "";

    for (int i = 0; i < (int)activeCases.size(); i++)
        if (activeCases[i].getLinkedCriminalID() == id)
            { caseStatus = "Active"; caseIDFound = activeCases[i].getCaseID(); }
    for (int i = 0; i < (int)closedCases.size(); i++)
        if (closedCases[i].getLinkedCriminalID() == id)
            { caseStatus = "Closed"; verdict = closedCases[i].getVerdict(); caseIDFound = closedCases[i].getCaseID(); }
    for (int i = 0; i < (int)evidences.size(); i++)
        if (evidences[i].getLinkedCriminalID() == id) evCount++;
    for (int i = 0; i < (int)witnesses.size(); i++)
        if (witnesses[i].getLinkedCriminalID() == id) wiCount++;
    for (int i = 0; i < (int)victims.size(); i++)
        if (victims[i].getLinkedCriminalID() == id) viCount++;

    cout << "\n  ====== CRIMINAL REPORT ======\n";
    cout << "  Name         : " << criminals[idx].getName() << "\n";
    cout << "  Age          : " << criminals[idx].getAge() << "\n";
    cout << "  CNIC         : " << criminals[idx].getCnic() << "\n";
    cout << "  Address      : " << criminals[idx].getAddress() << "\n";
    cout << "  Crime Type   : " << criminals[idx].getCrimeType() << "\n";
    cout << "  Threat Level : " << criminals[idx].getThreatLvl() << "\n";
    cout << "  Case ID      : " << caseIDFound << "\n";
    cout << "  Case Status  : " << caseStatus << "\n";
    cout << "  Verdict      : " << verdict << "\n";
    cout << "  Bail Status  : " << criminals[idx].getBailStatus() << "\n";
    cout << "  Evidence     : " << evCount << " item(s)\n";
    cout << "  Witnesses    : " << wiCount << "\n";
    cout << "  Victims      : " << viCount << "\n";
    cout << "  =============================\n";
    pressEnter();
}

void viewStats() {
    int mostWanted = 0, high = 0, medium = 0, low = 0, onBail = 0;
    for (int i = 0; i < (int)criminals.size(); i++) {
        if (criminals[i].getThreatLvl() == "MOST WANTED") mostWanted++;
        else if (criminals[i].getThreatLvl() == "HIGH") high++;
        else if (criminals[i].getThreatLvl() == "MEDIUM") medium++;
        else low++;
        if (criminals[i].getBailStatus() == "On Bail") onBail++;
    }
    cout << "\n  === CRIME STATISTICS ===\n";
    printLine();
    cout << "  Total Criminals  : " << criminals.size() << "\n";
    cout << "  Most Wanted      : " << mostWanted << "\n";
    cout << "  High Threat      : " << high << "\n";
    cout << "  Medium Threat    : " << medium << "\n";
    cout << "  Low Threat       : " << low << "\n";
    cout << "  On Bail          : " << onBail << "\n";
    cout << "  Active Cases     : " << activeCases.size() << "\n";
    cout << "  Closed Cases     : " << closedCases.size() << "\n";
    cout << "  Total Evidence   : " << evidences.size() << "\n";
    cout << "  Total Witnesses  : " << witnesses.size() << "\n";
    cout << "  Total Victims    : " << victims.size() << "\n";
    cout << "  Total Officers   : " << officers.size() << "\n";
    cout << "  Total Detectives : " << detectives.size() << "\n";
    printLine();
    pressEnter();
}

// ============================================================
//   DETECTIVE MENU FUNCTIONS
// ============================================================

void detectiveCloseCase(string detUsername) {
    cout << "\n  === CLOSE CASE ===\n";
    cout << "  Your assigned cases:\n";
    bool found = false;
    for (int i = 0; i < (int)activeCases.size(); i++) {
        if (activeCases[i].getAssignedDetectiveID() == detUsername) {
            activeCases[i].generateReport();
            found = true;
        }
    }
    if (!found) { cout << "  No assigned cases.\n"; pressEnter(); return; }

    string caseID  = getAnyString("  Enter Case ID to close: ");
    int idx = findActiveCase(caseID);
    if (idx == -1 || activeCases[idx].getAssignedDetectiveID() != detUsername) {
        cout << "  [!] Case not found or not assigned to you.\n"; pressEnter(); return;
    }

    string verdict   = getAnyString("  Verdict      : ");
    string closeDate = getAnyString("  Closing Date : ");

    ClosedCase cc(caseID,
                  activeCases[idx].getTitle(),
                  activeCases[idx].getDate(),
                  activeCases[idx].getDescription(),
                  activeCases[idx].getLinkedCriminalID(),
                  verdict, closeDate, detUsername);
    closedCases.push_back(cc);
    saveClosedCases();

    activeCases.erase(activeCases.begin() + idx);
    saveActiveCases();

    // Update detective caseload
    int didx = findDetective(detUsername);
    if (didx != -1) {
        detectives[didx].decreaseCaseLoad();
        saveDetectives();
    }

    cout << "\n  [+] Case closed and moved to Closed Cases. Stats updated.\n";
    pressEnter();
}

void detectiveViewAssignedCases(string detUsername) {
    cout << "\n  === MY ASSIGNED CASES ===\n";
    bool found = false;
    for (int i = 0; i < (int)activeCases.size(); i++) {
        if (activeCases[i].getAssignedDetectiveID() == detUsername) {
            activeCases[i].generateReport(); found = true;
        }
    }
    if (!found) cout << "  No cases assigned to you.\n";
    pressEnter();
}

void detectiveAddEvidence(string detUsername) {
    cout << "\n  === ADD EVIDENCE (Detective) ===\n";
    string caseID = getAnyString("  Case ID (must be your assigned case): ");
    int idx = findActiveCase(caseID);
    if (idx == -1 || activeCases[idx].getAssignedDetectiveID() != detUsername) {
        cout << "  [!] Case not found or not assigned to you.\n"; pressEnter(); return;
    }
    string crimID = activeCases[idx].getLinkedCriminalID();
    string type   = getAnyString("  Evidence Type  : ");
    string desc   = getAnyString("  Description    : ");
    string id     = genEvidenceID();
    Evidence e(id, type, desc, caseID, crimID);
    evidences.push_back(e);
    saveEvidence();
    cout << "\n  [+] Evidence added! ID: " << id << "\n";
    pressEnter();
}

void detectiveAddWitness(string detUsername) {
    cout << "\n  === ADD WITNESS (Detective) ===\n";
    string caseID = getAnyString("  Case ID (must be your assigned case): ");
    int idx = findActiveCase(caseID);
    if (idx == -1 || activeCases[idx].getAssignedDetectiveID() != detUsername) {
        cout << "  [!] Case not assigned to you.\n"; pressEnter(); return;
    }
    string crimID = activeCases[idx].getLinkedCriminalID();
    string name   = getValidString("  Witness Name      : ");
    int age       = getValidInt("  Age               : ");
    string cnic   = getAnyString("  CNIC              : ");
    string addr   = getAnyString("  Address           : ");
    string stmt   = getAnyString("  Statement         : ");
    string prot   = getAnyString("  Protection Status : ");
    string id     = genWitnessID();
    Witness w(id, name, age, cnic, addr, stmt, prot, caseID, crimID);
    witnesses.push_back(w);
    saveWitnesses();
    cout << "\n  [+] Witness added! ID: " << id << "\n";
    pressEnter();
}

// ============================================================
//   ADMIN MENU FUNCTIONS
// ============================================================

void adminScheduleMeeting() {
    cout << "\n  === SCHEDULE MEETING ===\n";
    cout << "  1. With Officer\n  2. With Detective\n";
    int ch = getValidInt("  Choice: ");
    string type = (ch == 1) ? "Officer" : "Detective";
    string username = getAnyString("  Enter Username: ");

    // Validate user exists
    bool exists = false;
    if (ch == 1) {
        for (int i = 0; i < (int)officers.size(); i++)
            if (officers[i].getUsername() == username) { exists = true; break; }
    } else {
        for (int i = 0; i < (int)detectives.size(); i++)
            if (detectives[i].getUsername() == username) { exists = true; break; }
    }
    if (!exists) { cout << "  [!] User not found.\n"; pressEnter(); return; }

    string date  = getAnyString("  Meeting Date : ");
    string mtime = getAnyString("  Meeting Time : ");

    // Check duplicate
    for (int i = 0; i < (int)meetings.size(); i++) {
        if (meetings[i].getPersonUsername() == username &&
            meetings[i].getMeetingDate()    == date &&
            meetings[i].getMeetingTime()    == mtime) {
            cout << "  [!] Meeting already scheduled for this person at this time!\n";
            pressEnter(); return;
        }
    }

    string id = genMeetingID();
    Meeting m(id, username, type, date, mtime);
    meetings.push_back(m);
    saveMeetings();
    cout << "\n  [+] Meeting scheduled! ID: " << id << "\n";
    pressEnter();
}

void adminViewMeetings() {
    cout << "\n  === ALL MEETINGS ===\n";
    if (meetings.empty()) { cout << "  No meetings scheduled.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)meetings.size(); i++)
        meetings[i].display();
    pressEnter();
}

void adminAssignCase() {
    cout << "\n  === ASSIGN CASE TO DETECTIVE ===\n";
    if (activeCases.empty()) { cout << "  No active cases.\n"; pressEnter(); return; }
    if (detectives.empty())  { cout << "  No detectives registered.\n"; pressEnter(); return; }

    cout << "  Active Cases:\n";
    for (int i = 0; i < (int)activeCases.size(); i++)
        cout << "  [" << activeCases[i].getCaseID() << "] " << activeCases[i].getTitle() << "\n";

    string caseID   = getAnyString("  Enter Case ID  : ");
    int cidx = findActiveCase(caseID);
    if (cidx == -1) { cout << "  [!] Case not found.\n"; pressEnter(); return; }

    cout << "\n  Detectives:\n";
    for (int i = 0; i < (int)detectives.size(); i++)
        cout << "  [" << detectives[i].getUsername() << "] " << detectives[i].getName() << " | CaseLoad: " << detectives[i].getCaseLoad() << "\n";

    string detUsername = getAnyString("  Enter Detective Username: ");
    int didx = findDetective(detUsername);
    if (didx == -1) { cout << "  [!] Detective not found.\n"; pressEnter(); return; }

    activeCases[cidx].setAssignedDetectiveID(detUsername);
    saveActiveCases();
    detectives[didx].increaseCaseLoad();
    saveDetectives();
    cout << "\n  [+] Case " << caseID << " assigned to Detective " << detUsername << "\n";
    pressEnter();
}

void adminApproveBail() {
    cout << "\n  === APPROVE BAIL ===\n";
    if (criminals.empty()) { cout << "  No criminals found.\n"; pressEnter(); return; }
    string crimID = getAnyString("  Enter Criminal ID: ");
    int idx = findCriminal(crimID);
    if (idx == -1) { cout << "  [!] Criminal not found.\n"; pressEnter(); return; }

    string amount = getAnyString("  Bail Amount (PKR): ");
    string date   = getAnyString("  Date             : ");
    string id     = genBailID();
    Bail b(id, crimID, criminals[idx].getName(), amount, date, "Admin");
    bails.push_back(b);
    saveBails();

    criminals[idx].setBailStatus("On Bail");
    saveCriminals();
    cout << "\n  [+] Bail approved! Criminal status: On Bail\n";
    pressEnter();
}

void adminViewAllCases() {
    cout << "\n  === ALL CASES (ADMIN VIEW) ===\n";
    cout << "\n  -- ACTIVE CASES --\n";
    if (activeCases.empty()) cout << "  None.\n";
    else for (int i = 0; i < (int)activeCases.size(); i++) activeCases[i].generateReport();
    cout << "\n  -- CLOSED CASES --\n";
    if (closedCases.empty()) cout << "  None.\n";
    else for (int i = 0; i < (int)closedCases.size(); i++) closedCases[i].generateReport();
    pressEnter();
}

void adminViewOfficers() {
    cout << "\n  === ALL OFFICERS ===\n";
    if (officers.empty()) { cout << "  No officers registered.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)officers.size(); i++) officers[i].getDetails();
    pressEnter();
}

void adminViewDetectives() {
    cout << "\n  === ALL DETECTIVES ===\n";
    if (detectives.empty()) { cout << "  No detectives registered.\n"; pressEnter(); return; }
    for (int i = 0; i < (int)detectives.size(); i++) detectives[i].getDetails();
    pressEnter();
}

// ============================================================
//   LOGIN & REGISTER FUNCTIONS
// ============================================================

bool officerLogin(string& loggedUsername, string& loggedName) {
    cout << "\n  === OFFICER LOGIN ===\n";
    string user = getAnyString("  Username: ");
    string pass = getAnyString("  Password: ");
    for (int i = 0; i < (int)officers.size(); i++) {
        if (officers[i].getUsername() == user && officers[i].getPassword() == pass) {
            loggedUsername = user;
            loggedName     = officers[i].getName();
            cout << "\n  [+] Welcome, Officer " << loggedName << "!\n";
            return true;
        }
    }
    cout << "  [!] Invalid credentials.\n";
    return false;
}

bool detectiveLogin(string& loggedUsername, string& loggedName) {
    cout << "\n  === DETECTIVE LOGIN ===\n";
    string user = getAnyString("  Username: ");
    string pass = getAnyString("  Password: ");
    for (int i = 0; i < (int)detectives.size(); i++) {
        if (detectives[i].getUsername() == user && detectives[i].getPassword() == pass) {
            loggedUsername = user;
            loggedName     = detectives[i].getName();
            cout << "\n  [+] Welcome, Detective " << loggedName << "!\n";
            return true;
        }
    }
    cout << "  [!] Invalid credentials.\n";
    return false;
}

void registerOfficer() {
    cout << "\n  === REGISTER OFFICER ===\n";
    string name   = getValidString("  Full Name    : ");
    int age       = getValidInt("  Age          : ");
    string cnic   = getAnyString("  CNIC         : ");
    string addr   = getAnyString("  Address      : ");
    string user   = getAnyString("  Username     : ");
    // Check duplicate username
    for (int i = 0; i < (int)officers.size(); i++) {
        if (officers[i].getUsername() == user) {
            cout << "  [!] Username already taken. Try again.\n"; return;
        }
    }
    string pass   = getAnyString("  Password     : ");
    string badge  = getAnyString("  Badge No     : ");
    string dept   = getAnyString("  Department   : ");
    string rank   = getValidString("  Rank         : ");
    string id     = genOfficerID();
    Officer o(id, name, age, cnic, addr, user, pass, badge, dept, rank);
    officers.push_back(o);
    saveOfficers();
    cout << "\n  [+] Officer registered! ID: " << id << "\n";
    pressEnter();
}

void registerDetective() {
    cout << "\n  === REGISTER DETECTIVE ===\n";
    string name   = getValidString("  Full Name       : ");
    int age       = getValidInt("  Age             : ");
    string cnic   = getAnyString("  CNIC            : ");
    string addr   = getAnyString("  Address         : ");
    string user   = getAnyString("  Username        : ");
    for (int i = 0; i < (int)detectives.size(); i++) {
        if (detectives[i].getUsername() == user) {
            cout << "  [!] Username already taken. Try again.\n"; return;
        }
    }
    string pass   = getAnyString("  Password        : ");
    string spec   = getAnyString("  Specialization  : ");
    string id     = genDetectiveID();
    Detective d(id, name, age, cnic, addr, user, pass, spec);
    detectives.push_back(d);
    saveDetectives();
    cout << "\n  [+] Detective registered! ID: " << id << "\n";
    pressEnter();
}

// ============================================================
//   MENUS
// ============================================================

void officerMenu(string username, string name) {
    int ch;
    do {
        clearScreen();
        cout << "\n  ==========================================\n";
        cout << "    OFFICER MENU - " << name << "\n";
        cout << "  ==========================================\n";
        cout << "   1.  Add Criminal\n";
        cout << "   2.  View All Criminals\n";
        cout << "   3.  Update Criminal\n";
        cout << "   4.  Delete Criminal\n";
        cout << "   5.  Add Case\n";
        cout << "   6.  View Active Cases\n";
        cout << "   7.  View Closed Cases\n";
        cout << "   8.  Update Case\n";
        cout << "   9.  Add Evidence\n";
        cout << "   10. View Evidence\n";
        cout << "   11. Add Witness\n";
        cout << "   12. View Witnesses\n";
        cout << "   13. Add Victim\n";
        cout << "   14. View Victims\n";
        cout << "   15. Add Arrest\n";
        cout << "   16. View Arrests\n";
        cout << "   17. Add Crime Scene\n";
        cout << "   18. View Crime Scenes\n";
        cout << "   19. Add Court Hearing\n";
        cout << "   20. View Court Hearings\n";
        cout << "   21. Search & Filter\n";
        cout << "   22. View Notifications\n";
        cout << "   23. Generate Report\n";
        cout << "   24. Crime Statistics\n";
        cout << "   0.  Logout\n";
        cout << "  ==========================================\n";
        ch = getValidInt("  Choice: ");
        if      (ch == 1)  addCriminal(name);
        else if (ch == 2)  viewAllCriminals();
        else if (ch == 3)  updateCriminal();
        else if (ch == 4)  deleteCriminal();
        else if (ch == 5)  addCase();
        else if (ch == 6)  viewActiveCases();
        else if (ch == 7)  viewClosedCases();
        else if (ch == 8)  updateCase();
        else if (ch == 9)  addEvidence(name);
        else if (ch == 10) viewEvidence();
        else if (ch == 11) addWitness();
        else if (ch == 12) viewWitnesses();
        else if (ch == 13) addVictim();
        else if (ch == 14) viewVictims();
        else if (ch == 15) addArrest(name);
        else if (ch == 16) viewArrests();
        else if (ch == 17) addCrimeScene();
        else if (ch == 18) viewCrimeScenes();
        else if (ch == 19) addCourtHearing();
        else if (ch == 20) viewCourtHearings();
        else if (ch == 21) searchAndFilter();
        else if (ch == 22) viewNotifications();
        else if (ch == 23) generateReport();
        else if (ch == 24) viewStats();
        else if (ch != 0)  cout << "  [!] Invalid choice.\n";
    } while (ch != 0);
    cout << "\n  [+] Officer logged out.\n";
}

void detectiveMenu(string username, string name) {
    int ch;
    do {
        clearScreen();
        cout << "\n  ==========================================\n";
        cout << "    DETECTIVE MENU - " << name << "\n";
        cout << "  ==========================================\n";
        cout << "   1.  View My Assigned Cases\n";
        cout << "   2.  Add Evidence\n";
        cout << "   3.  Add Witness\n";
        cout << "   4.  View Evidence\n";
        cout << "   5.  View Witnesses\n";
        cout << "   6.  View Victims\n";
        cout << "   7.  View Crime Scenes\n";
        cout << "   8.  View Court Hearings\n";
        cout << "   9.  Search & Filter Criminals\n";
        cout << "   10. View Notifications\n";
        cout << "   11. Generate Report\n";
        cout << "   12. Close Case\n";
        cout << "   13. Crime Statistics\n";
        cout << "   0.  Logout\n";
        cout << "  ==========================================\n";
        ch = getValidInt("  Choice: ");
        if      (ch == 1)  detectiveViewAssignedCases(username);
        else if (ch == 2)  detectiveAddEvidence(username);
        else if (ch == 3)  detectiveAddWitness(username);
        else if (ch == 4)  viewEvidence();
        else if (ch == 5)  viewWitnesses();
        else if (ch == 6)  viewVictims();
        else if (ch == 7)  viewCrimeScenes();
        else if (ch == 8)  viewCourtHearings();
        else if (ch == 9)  searchAndFilter();
        else if (ch == 10) viewNotifications();
        else if (ch == 11) generateReport();
        else if (ch == 12) detectiveCloseCase(username);
        else if (ch == 13) viewStats();
        else if (ch != 0)  cout << "  [!] Invalid choice.\n";
    } while (ch != 0);
    cout << "\n  [+] Detective logged out.\n";
}

void adminMenu() {
    int ch;
    do {
        clearScreen();
        cout << "\n  ==========================================\n";
        cout << "         ADMIN PANEL\n";
        cout << "  ==========================================\n";
        cout << "   1.  View All Officers\n";
        cout << "   2.  View All Detectives\n";
        cout << "   3.  View All Cases\n";
        cout << "   4.  Assign Case to Detective\n";
        cout << "   5.  Approve Bail\n";
        cout << "   6.  Schedule Meeting\n";
        cout << "   7.  View All Meetings\n";
        cout << "   8.  View All Criminals\n";
        cout << "   9.  View Notifications\n";
        cout << "   10. Crime Statistics\n";
        cout << "   0.  Logout\n";
        cout << "  ==========================================\n";
        ch = getValidInt("  Choice: ");
        if      (ch == 1)  adminViewOfficers();
        else if (ch == 2)  adminViewDetectives();
        else if (ch == 3)  adminViewAllCases();
        else if (ch == 4)  adminAssignCase();
        else if (ch == 5)  adminApproveBail();
        else if (ch == 6)  adminScheduleMeeting();
        else if (ch == 7)  adminViewMeetings();
        else if (ch == 8)  viewAllCriminals();
        else if (ch == 9)  viewNotifications();
        else if (ch == 10) viewStats();
        else if (ch != 0)  cout << "  [!] Invalid choice.\n";
    } while (ch != 0);
    cout << "\n  [+] Admin logged out.\n";
}

// ============================================================
//   MAIN FUNCTION
// ============================================================

int main() {
    loadAllData();

    int ch;
    do {
        clearScreen();
        cout << "\n  ==========================================\n";
        cout << "   CRIMINAL RECORD MANAGEMENT SYSTEM\n";
        cout << "  ==========================================\n";
        cout << "   1. Admin Login\n";
        cout << "   2. Officer Register\n";
        cout << "   3. Officer Login\n";
        cout << "   4. Detective Register\n";
        cout << "   5. Detective Login\n";
        cout << "   0. Exit\n";
        cout << "  ==========================================\n";
        ch = getValidInt("  Choice: ");

        if (ch == 1) {
            cout << "\n  === ADMIN LOGIN ===\n";
            string user = getAnyString("  Username: ");
            string pass = getAnyString("  Password: ");
            if (user == "Admin" && pass == "CYS") {
                cout << "\n  [+] Welcome, Admin!\n";
                adminMenu();
            } else {
                cout << "  [!] Invalid admin credentials.\n";
            }
        } else if (ch == 2) {
            registerOfficer();
        } else if (ch == 3) {
            string uname, ulogname;
            if (officerLogin(uname, ulogname))
                officerMenu(uname, ulogname);
        } else if (ch == 4) {
            registerDetective();
        } else if (ch == 5) {
            string uname, ulogname;
            if (detectiveLogin(uname, ulogname))
                detectiveMenu(uname, ulogname);
        } else if (ch != 0) {
            cout << "  [!] Invalid choice.\n";
        }
    } while (ch != 0);

    cout << "\n  Goodbye!\n";
    return 0;
}

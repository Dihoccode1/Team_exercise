    #include <bits/stdc++.h>
    using namespace std;
    struct Dayofbirth
    {
        Dayofbirth()
        {
            day = 0;
            month = 0;
            year = 0;
        }
        int day;
        int month;
        int year;
    };
    struct Student
    {
        int ID;
        string firstname_lastname;
        string name;
        Dayofbirth dob;
        bool gender;
        double GPA;
    };
    void Input_data(Student* &A_student, int &numberofStudent);
    void Print_list_student(fstream &file, Student *A_student, int numberofStudent);
    void Read_list_student(fstream &file, Student *A_student, int numberofStudent);
    void sortListStudentbyID(Student* &A_student, int numberofStudent);
    void Print_list_after_sort_by_id(Student* A_student, int numberofStudent);
    int main ()
    {
        Student *A_student;
        int numberofStudent;
        fstream file;
        Input_data(A_student, numberofStudent);
        Print_list_student(file, A_student, numberofStudent);
        Read_list_student(file, A_student, numberofStudent);
        sortListStudentbyID(A_student, numberofStudent);
        Print_list_after_sort_by_id(A_student, numberofStudent);
        return 0;
    }
    void Input_data(Student* &A_student, int &numberofStudent)
    {
        cout<<"Nhập số lượng sinh viên: ";
        cin>>numberofStudent;
        A_student = new Student[numberofStudent];
        for(int i=0; i<numberofStudent; i++)
        {
            cout<<"Nhập thông tin sinh viên thứ "<<i+1<<endl;
            cout<<"Nhập ID: ";
            cin>>A_student[i].ID;
            cin.ignore();
            cout<<"Nhập họ và tên: ";
            getline(cin,A_student[i].firstname_lastname);
            cout<<"Nhập tên: ";
            getline(cin,A_student[i].name);
            cout<<"Nhập ngày sinh: ";
            cin>>A_student[i].dob.day;
            cout<<"Nhập tháng sinh: ";
            cin>>A_student[i].dob.month;
            cout<<"Nhập năm sinh: ";
            cin>>A_student[i].dob.year;
            cout<<"Nhập giới tính (Nam: 1, Nữ: 0): ";
            cin>>A_student[i].gender;
            cout<<"Nhập điểm trung bình: ";
            cin>>A_student[i].GPA;
    }
    }
    void Print_list_student(fstream &file, Student *A_student, int numberofStudent)
    {
        file.open("C:\\WorkSpace\\DSA\\TeamExcercise\\bai9vandung\\SINHVIEN.DAT", ios::out);
        for(int i=0; i<numberofStudent; i++)
        {
            file<<A_student[i].ID<<" ";
            file<<A_student[i].firstname_lastname<<" ";
            file<<A_student[i].name<<" ";
            file<<A_student[i].dob.day<<" ";
            file<<A_student[i].dob.month<<" ";
            file<<A_student[i].dob.year<<" ";
            file<<A_student[i].gender<<" ";
            if(A_student[i].gender==1)
                {
                    file<<"Nam ";
                }
            else
                {
                    file<<"Nữ ";
                }
            file<<A_student[i].GPA<<endl;
        }
    file.close();
    }
void Read_list_student(fstream &file, Student *A_student, int numberofStudent)
{
    file.open("C:\\WorkSpace\\DSA\\TeamExcercise\\bai9vandung\\SINHVIEN.DAT", ios::in);
    for(int i=0; i<numberofStudent; i++)
    {
        file>>A_student[i].ID;
        file>>A_student[i].firstname_lastname;
        file>>A_student[i].name;
        file>>A_student[i].dob.day;
        file>>A_student[i].dob.month;
        file>>A_student[i].dob.year;
        string genders;
        file>>genders;
        if(genders=="Nam")
        {
            A_student[i].gender=1;
        }
        else
        {
            A_student[i].gender=0;
        }
        file>>A_student[i].GPA;
    }
}
void sortListStudentbyID(Student* &A_student, int numberofStudent)
{
    for(int i=0;i<numberofStudent-1;i++)
    {
        int Min_index=i;
        for(int j=i+1;j<numberofStudent;j++)
        {
            if(A_student[j].ID<A_student[Min_index].ID)
            {
                Min_index=j;
            }
        }
        swap(A_student[i],A_student[Min_index]);
    }
}
void Print_list_after_sort_by_id(Student* A_student, int numberofStudent)
{
    cout << left << setw(10) << "ID" 
         << setw(25) << "Họ và tên" 
         << setw(15) << "Tên" 
         << setw(12) << "Ngày sinh" 
         << setw(10) << "Giới tính" 
         << setw(5) << "GPA" << endl;
    cout << string(77, '-') << endl; // In dòng kẻ ngang để phân cách

    for (int i = 0; i < numberofStudent; i++) {
        cout << left << setw(10) << A_student[i].ID 
             << setw(25) << A_student[i].firstname_lastname 
             << setw(15) << A_student[i].name 
             << setfill('0') << setw(2) << A_student[i].dob.day << "/" 
             << setfill('0') << setw(2) << A_student[i].dob.month << "/" 
             << setfill(' ') << setw(8) << A_student[i].dob.year 
             << setw(10) << (A_student[i].gender ? "Nam" : "Nữ") 
             << setw(5) << fixed << setprecision(2) << A_student[i].GPA 
             << endl;
    }
}
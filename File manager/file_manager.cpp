#include "file_manager.h"

File::File(const char* mName) : name(mName), out(mName) {
    if (!out)cout << "File didn't open";
}
File::File(File& mFile) : name(mFile.name) {}
File::File() {}


void File::clear()
{
    ofstream ofs;
    ofs.open(name, ios::trunc);
    ofs.close();
}

void File::write(const char* txt)
{
    clear();
    out << txt << endl;
}

void File::write(const vector<string>& vec)
{
    clear();
    for (int i = 0; i < vec.size(); ++i)
        out << vec[i] << endl;
}

vector<string> File::read_vec()
{
    vector<string> vec;
    ifstream in(name);
    while (in)
    {
        string s;
        getline(in, s);
        vec.push_back(s);
    }
    return vec;
}

string File::read()
{
    ifstream in(name);
    string txt;
    while (in)
    {
        string s;
        getline(in, s);
        txt += s + "\n";
    }
    return txt;
}
File& operator<<(File& file, const vector<string>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
        file.out << vec[i] << endl;
    return file;
}
File& operator>>(File& file, string& str)
{
    ifstream in(file.name);
    string txt;
    while (in)
    {
        string s;
        getline(in, s);
        txt = txt + s + "\n";
    }
    str = txt;
    return file;
}
ostream& operator<<(ostream& out, File& file)
{
    ifstream in(file.name);
    while (in)
    {
        string s;
        getline(in, s);
        cout << s << "\n";
    }

    return out;
}
File& operator<<(File& file, const char* text)
{
    file.out << text << endl;
    return file;
}

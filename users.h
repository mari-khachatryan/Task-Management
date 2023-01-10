
class Users {
public:
    Users() : age(0), id(0) { }
    Users(const std::string& userName, const std::string& userSurname,const std::string& userGmail, const int& userAge, const int& userId);
     ~Users() { }

    void setName(const std::string& userName) { name = userName; }
    std::string getName() { return name; }

    void setSurName(const std::string& userSurName) { surName = userSurName; }
    std::string getSurName() { return surName; }

    void setGmail(const std::string& userGmail) { gmail = userGmail; }
    std::string getGmail() { return gmail; }

    void setAge(int userAge) { age = userAge; }
    int getAge() { return age; }

    void setId(int userId) { id = userId; }
    int getId() { return id; }

    void insert();
    void selectWithName(const std::string& path, const std::string& name);
    void selectWithSername(const std::string& path, const std::string& name);
    void selectWithAge(const std::string& path, int age);
    void update(const std::string& gmail, const std::string& path);
    void deleted(const std::string& gmail, const std::string& path);
private:
    std::string name;
    std::string surName;
    std::string gmail;
    int age;
    int id;
};






















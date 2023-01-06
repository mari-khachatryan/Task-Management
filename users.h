
class Users {
public:
    Users() : age(0), id(0) { }
    Users(const std::string& userName, const std::string& userSurname, const int& userAge, const int& userId);
     ~Users() { std::cout << "User add in data base"; }

    void setName(const std::string& userName) { name = userName; }
    std::string getName() { return name; }

    void setSurName(const std::string& userSurName) { surName = userSurName; }
    std::string getSurName() { return surName; }

    void setAge(int userAge) { age = userAge; }
    int getAge() { return age; }

    void setId(int userId) { id = userId; }
    int getId() { return id; }

    //void insert(const std::string& path);
    void insert();
    void selectWithName(const std::string& path, const std::string& name);
    void selectWithSername(const std::string& path, const std::string& name);
private:
    std::string name;
    std::string surName;
    int age;
    int id;
};






















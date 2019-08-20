//
// Created by zhaohan on 2019/8/1.
//

class Singleton{
public:
    static Singleton& GetInstance();

private:
    Singleton(){}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    static Singleton m_Instance;
};

//cpp文件
Singleton Singleton::m_Instance;

Singleton& Singleton::GetInstance() {
    return m_Instance;
}

//函数调用
Singleton& instance = Singleton::GetInstance();
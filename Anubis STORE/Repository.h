#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template <class T>
class Repository {
private:
    std::vector<T> vector;
    std::string fileName;

public:
    Repository();
    explicit Repository(const std::string& fileName);
    ~Repository();

    int getLenght();

    void addElem(const T& elem);
    void updateElem(const T& oldElem, const T& newElem);
    void deleteElem(const T& elem);
    std::vector<T> getAll();

    // Wallet
    void addWalletApp(const T& wallet);

private:
    void saveToFile();
    void loadFromFile();

    void saveToFileWallet();

};

template<class T> Repository<T>::Repository() {
    this->fileName = " ";
}

template<class T> Repository<T>::Repository(const std::string& fileName) {
    this->fileName = fileName;
    this->loadFromFile();
}

template<class T> std::vector<T> Repository<T>::getAll() {
    return this->vector;
};

template<class T> int Repository<T>::getLenght() {
    return this->vector.size();
}

template<class T> void Repository<T>::addElem(const T& elem) {
    this->vector.push_back(elem);

    // Save to file if the file is not empty

    if (this->fileName != " ")
        this->saveToFile();

};

template<class T> void Repository<T>::updateElem(const T& oldElem, const T& newElem) {
    for (int i = 0; i < this->vector.size(); i++)
        if (this->vector[i] == oldElem)
            this->vector[i] = newElem;

    this->saveToFile();
};

template<class T> void Repository<T>::deleteElem(const T& elem) {
    typename std::vector<T>::iterator it = find(this->vector.begin(), this->vector.end(), elem);
    if (it != this->vector.end())
        this->vector.erase(it);

    // Save to file if the file is not empty
    if (this->fileName != " ")
        this->saveToFile();
};


template<class T> void Repository<T>::saveToFile() {
    // We need to save to file here..
    if (this->fileName.empty()) {
        std::cout << "I can't save to file\n";
    }
    else {
        std::ofstream file(this->fileName);

        for (int i = 0; i < this->vector.size(); i++)
            if (i < this->vector.size() - 1)
                file << this->vector[i] << '\n';
            else
                file << this->vector[i];
        file.close();
    }
}

template<class T> void Repository<T>::loadFromFile() {
    if (this->fileName.empty()) {
        std::cout << "The file is empty !!!! \n";
    }
    else {
        std::ifstream file(this->fileName);
        T element;
        if (file.is_open())
            while (!file.eof()) {
                file >> element;
                if (!(element == T()))
                    this->vector.push_back(element);
            }
        file.close();
    }
}

template<class T> void Repository<T>::saveToFileWallet() {
    if (this->fileName.empty())
        std::cout << "I can't save to file\n";
    else {
        std::ofstream file(this->fileName);
        file << "";
        file << this->vector[this->vector.size() - 1];
        file.close();
    }
}

template<class T> void Repository<T>::addWalletApp(const T& wallet) {
    this->vector.push_back(wallet);
    this->saveToFileWallet();
}

template<class T> Repository<T>::~Repository() = default;


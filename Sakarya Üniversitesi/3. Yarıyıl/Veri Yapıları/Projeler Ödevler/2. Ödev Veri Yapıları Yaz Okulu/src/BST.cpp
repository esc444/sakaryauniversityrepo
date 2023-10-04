/**
* @file BST.cpp
* @description "BST.h" başlık dosyasında tanımlanan İkili Arama Ağacı (BST - Binary Search Tree)
sınıfının fonksiyonlarının nasıl çalıştığının detaylarını içerir.
* @course 1.Öğretim- A Grubu- Dr.Öğr.Üyesi MUHAMMED FATİH ADAK
* @assignment 2.Ödev
* @date 06.08.2023
* @author Melih Tufan Atlı- melih.atli@ogr.sakarya.edu.tr            
          Ekrem Selçuk Çelik-ekrem.celik4@ogr.sakarya.edu.tr
*/
#include "BST.h"
#include <iostream>
#include <sstream>

BST::BST() : root(nullptr) {}// Kurucu fonksiyon
BST::~BST() {// Yıkıcı fonksiyon
    clearRec(root);// Ağacı temizler
}
void BST::clearRec(Node* node) {// Ağacı temizleme fonksiyonu
    if (node) {
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }
}
void BST::insert(int value) {// Ekleme fonksiyonu
    root = insertRec(root, value);// Recursive ekleme
}

int BST::height() const {// Yükseklik hesaplama fonksiyonu
    return heightRec(root);
}

int BST::sum() const {// Toplam değer hesaplama fonksiyonu
    return sumRec(root);
}

void BST::postorderPrint() const {// Post-order düzeninde ağacı yazdırma fonksiyonu
    postorderRec(root);
    std::cout << std::endl;
}
// Recursive ekleme fonksiyonu
Node* BST::insertRec(Node* node, int value) const {
    if (!node) {
        return new Node(value);
    }
// Veri değerini karşılaştırarak ilgili alt ağaca ekler
    if (value < node->data) {
        node->left = insertRec(node->left, value);
    } else if (value > node->data) {
        node->right = insertRec(node->right, value);
    }

    return node;
}
// Recursive yükseklik hesaplama fonksiyonu
int BST::heightRec(Node* node) const {
    if (!node) {
        return 0;
    }

    int leftHeight = heightRec(node->left);
    int rightHeight = heightRec(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}
// Recursive toplam hesaplama fonksiyonu
int BST::sumRec(Node* node) const {
    if (!node) {
        return 0;
    }

    return node->data + sumRec(node->left) + sumRec(node->right);
}
// Recursive post-order yazdırma fonksiyonu
void BST::postorderRec(Node* node) const {
    if (!node) {
        return;
    }

    postorderRec(node->left);
    postorderRec(node->right);
    std::cout << static_cast<char>(node->data);
    std::cout << " ";
}
// Stack'ten ağaç oluşturma fonksiyonu
BST BST::constructTreeFromStack(std::stack<int>& s) {
    BST tree;
    while (!s.empty()) {
        tree.insert(s.top());// Stack'teki üstteki değeri ağaca ekle
        s.pop();// Stack'ten değeri çıkar
    }
    return tree;
}
// Satırı işleme ve en iyi ağacı bulma fonksiyonu
// Bu fonksiyon, verilen satırdaki sayıları kullanarak bir dizi ağaç oluşturur
    // ve en yüksek veya en büyük toplam değere sahip olanı "bestTree" olarak saklar.
void BST::processLine(const std::string& line, BST& bestTree) {
    std::istringstream iss(line);
    int number;
    std::stack<int> currentStack;
    bool newStack = true;

    int maxHeight = -1;
    int maxSum = -1;

    while (iss >> number) {
        if (newStack || (number % 2 == 0 && number > currentStack.top())) {
            BST tree = constructTreeFromStack(currentStack);
            int currentHeight = tree.height();
            int currentSum = tree.sum();

            if (currentHeight > maxHeight || (currentHeight == maxHeight && currentSum > maxSum)) {
                maxHeight = currentHeight;
                maxSum = currentSum;
                bestTree = tree;
            }

            newStack = false;
        }
        currentStack.push(number);
    }

    if (!currentStack.empty()) {
        BST tree = constructTreeFromStack(currentStack);
        int currentHeight = tree.height();
        int currentSum = tree.sum();

        if (currentHeight > maxHeight || (currentHeight == maxHeight && currentSum > maxSum)) {
            maxHeight = currentHeight;
            maxSum = currentSum;
            bestTree = tree;
        }
    }
}
// Kopya yapıcı
BST::BST(const BST& other) {
    root = copyTree(other.root);
}

// Kopya atama operatörü
BST& BST::operator=(const BST& other) {
    if (this != &other) { // Kendi kendine atama kontrolü
        clearRec(root);  // Mevcut ağacı silin
        root = copyTree(other.root); // Diğer ağacın bir kopyasını oluşturun
    }
    return *this;
}

// Ağacın bir kopyasını oluşturmak için yardımcı fonksiyon
Node* BST::copyTree(const Node* source) {
    if (!source) {
        return nullptr;
    }
    Node* newNode = new Node(source->data);
    newNode->left = copyTree(source->left);
    newNode->right = copyTree(source->right);
    return newNode;
}

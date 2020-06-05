#include "tree.h"

treeNode::treeNode(string w, string m, int c)
{
    word = w;
    meaning = m;
    count = c;

    left = NULL;
    right = NULL;
}


void treeNode::setData(string w, string m, int c)
{
    word = w;
    meaning = m;
    count = c;
}


void treeNode::DisplayWordMeaning()
{
    count += 1;
    cout << "Английское слово        : " << word << "\n" << "Значение                : " << meaning << "\n" << "Количество обращений    : " << count << endl;
    cout << "_____________________________________" << endl;
}


string treeNode::getWord()
{
    return word;
}
string treeNode::getMeaning()
{
    return meaning;
}
int treeNode::getCount()
{
    return count;
}


void treeNode::setLeft(treeNode* l)
{
    left = l;
}
void treeNode::setRight(treeNode* r)
{
    right = r;
}


treeNode* treeNode::getRight()
{
    return right;
}
treeNode* treeNode::getLeft()
{
    return left;
}


unsigned int DJBHash(string str)
{
    unsigned int hash = 5381;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        hash = ((hash << 5) + hash) + str[i];
    }
    return hash;
}


treeNode* FindMin(treeNode* T)
{
    if (T == NULL)
        return NULL;
    else if (T->getLeft() == NULL)
        return T;
    else
        return FindMin(T->getLeft());
}

bool Find(treeNode* root, string wrd)
{
    if (root != NULL)
    {

        if (Find(root->getLeft(), wrd) == true)  return true;
        if (Find(root->getRight(), wrd) == true) return true;
        if (wrd == root->getWord())
        {
            root->DisplayWordMeaning();
            return true;
        }
        else
            return false;

    }
    else return false;
}


void Edit(treeNode* root, string wrd, string newWrd, string mng, int cnt)
{
    if (root != NULL)
    {
        Edit(root->getLeft(), wrd, newWrd, mng, cnt);
        Edit(root->getRight(), wrd, newWrd, mng, cnt);
        if (wrd == root->getWord())
        {
            root->setData(newWrd, mng, cnt);
        }
    }
}


void insert(treeNode* root, string wrd, string mng, int cnt)
{
    unsigned int d = 0;
    treeNode* Newnode = new treeNode(wrd, mng, cnt);
    treeNode* p, * q;
    p = q = root;
    d = DJBHash(wrd);
    while (d != DJBHash(p->getWord()) && q != NULL)
    {
        p = q;
        if (d < DJBHash(p->getWord()))
        {
            q = p->getLeft();
        }
        else
        {
            q = p->getRight();
        }

    }
    if (d == DJBHash(p->getWord()))
    {
        cout << endl << "Дублируещее значение :" << p->getWord() << endl;

    }
    else if (d < DJBHash(p->getWord()))
    {
        p->setLeft(Newnode);
    }
    else if (d > DJBHash(p->getWord()))
    {
        p->setRight(Newnode);
    }
}



void insert2(treeNode* root2, string wrd, string mng, int cnt)
{
    int d = 0;
    treeNode* Newnode = new treeNode(wrd, mng, cnt);
    treeNode* p, * q;
    p = q = root2;
    d = cnt;
    while (d != (p->getCount()) && q != NULL)
    {
        p = q;
        if (d < (p->getCount()))
        {
            q = p->getLeft();
        }
        else
        {
            q = p->getRight();
        }

    }
    if (d == (p->getCount()))
    {
        cout << endl << "Дублируещее количество обращений :" << p->getCount() << endl;

    }
    else if (d < (p->getCount()))
    {
        p->setLeft(Newnode);
    }
    else if (d > (p->getCount()))
    {
        p->setRight(Newnode);
    }
}


void printDictionary(treeNode* root)
{
    if (root != NULL)
    {
        root->DisplayWordMeaning();
        printDictionary(root->getLeft());
        printDictionary(root->getRight());
    }

}


void DeleteDictionary(treeNode* root)
{
    if (root != NULL)
    {
        DeleteDictionary(root->getLeft());
        DeleteDictionary(root->getRight());
        delete root;
    }
}


treeNode* Delete(treeNode* root, string wrd)
{
    treeNode* tmpCell;
    if (root == NULL)
    {
        cout << "Элемент не найден" << endl;
        return NULL;
    }
    else if (DJBHash(wrd) < DJBHash(root->getWord()))       // Go Left
        root->setLeft(Delete(root->getLeft(), wrd));
    else if (DJBHash(wrd) > DJBHash(root->getWord()))       // Go Right
        root->setRight(Delete(root->getRight(), wrd));

    else if (root->getLeft() && root->getRight())           // Two children
    {
        tmpCell = FindMin(root->getRight());
        root->setData(tmpCell->getWord(), tmpCell->getMeaning(), tmpCell->getCount());
        root->setRight(Delete(root->getRight(), wrd));
    }
    else                                                   // one Child or zero   
    {
        tmpCell = root;
        if (root->getLeft() == NULL)
            root = root->getRight();
        else if (root->getRight() == NULL)
            root = root->getLeft();
        delete tmpCell;
    }

    return root;
}

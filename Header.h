#pragma once
using namespace System;

ref class Node {
public:
	int key; // ¬ершинка
	Node^ left; //ссылка на левую веточку
	Node^ right;//ссылка на правую веточку
	Node()
	{
		left = nullptr;
		right = nullptr;
	}
};

ref class Tree
{
	Node^ root; // ”казатель на корень.
public:
	Tree() 
	{
		root = nullptr;
	}

	~Tree()
	{
		root = nullptr;
	}
	

	Node^ Search(int key)
	{
		if (root != nullptr)
			return search(key, root);
	}

	void insert(int key)
	{
		if (root != nullptr)			
			insert(key, root);		

		else				      
		{
			root = gcnew Node;		      
			root->key = key;	      
										
			root->left = nullptr;		
			root->right = nullptr;		
		}
	}
	void InListBox(System::Windows::Forms::ListBox^ lb)
	{
		lb->Items->Clear();
		if (root != nullptr)
		{
			line(lb, root);
		}
	}
	bool isFullTree()
	{
		if (root == nullptr) return true;
		else return isFullTree(root);
	}
private:bool isFullTree(Node^ leaf)
{
	if (leaf == nullptr) return false;
	else
	{
		if (leaf->left == nullptr && leaf->right == nullptr)
			return true;
		else
		{
			return (isFullTree(leaf->left) && isFullTree(leaf->right));
		}
	}

}

private: void line(System::Windows::Forms::ListBox^ lb, Node^ leaf)
{
	if (leaf != nullptr)
	{
		if (leaf->left != nullptr)
		{
			if (leaf->right != nullptr)
			{
				lb->Items->Add(System::String::Format("{0}, left: {1}, right: {2}", leaf->key, leaf->left->key, leaf->right->key));
			}
			else lb->Items->Add(System::String::Format("{0}, left: {1}", leaf->key, leaf->left->key));
		}
		else
		{
			if (leaf->right != nullptr)
			lb->Items->Add(System::String::Format("{0}, right: {1}", leaf->key, leaf->right->key));
			else lb->Items->Add(System::String::Format("{0}", leaf->key));
		}
		line(lb, leaf->left);
		line(lb, leaf->right);
	}
}
							
private:void insert(int key, Node^ leaf)
	{
		if (key < leaf->key)  
		{
			if (leaf->left != nullptr)		
				insert(key, leaf->left);		
			else	
			{
				leaf->left = gcnew Node;		
				leaf->left->key = key;	
				leaf->left->left = nullptr;    
				leaf->left->right = nullptr;   	
			}
		}
		else if (key >= leaf->key)		
		{
			if (leaf->right != nullptr)		
				insert(key, leaf->right);		
			else		
			{
				leaf->right = gcnew Node;		
				leaf->right->key = key;	
				leaf->right->left = nullptr;  	
				leaf->right->right = nullptr;      
			}
		}
	}

private:Node^ search(int key, Node^ leaf)
	{
		if (leaf != nullptr)	
		{
			if (key == leaf->key)	
				return leaf;	
			if (key < leaf->key)	
				return search(key, leaf->left);	
			else		
				return search(key, leaf->right);
		}
		else return nullptr;					
	}

}; 


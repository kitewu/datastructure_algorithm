#include <iostream>
using namespace std;

const int MaxCSTreeSize = 20;
//结点类
template<class T>
class CSNode
{
public:
	CSNode();
	CSNode(CSNode<T>* firstchild,CSNode<T>* nextsibling,T newdata);
	CSNode<T>* getFirstChild();
	CSNode<T>* getNextSibling();
	T getData();
	void setFirstChild(T newData);
	void setNextsibling(T newData);
public:
	T data;
	CSNode* firstchild;
	CSNode* nextsibling;
};

template<class T>
CSNode<T>::CSNode()
{
	firstchild = NULL;
	nextsibling = NULL;
}

template<class T>
CSNode<T>::CSNode(CSNode<T>* firstchild,CSNode<T>* nextsibling,T newdata):firstchild(firstchild),nextsibling(nextsibling),data(newdata)
{}

template<class T>
CSNode<T>* CSNode<T>::getFirstChild()
{
	return firstchild;
}

template<class T>
CSNode<T>* CSNode<T>::getNextSibling()
{
	return nextsibling;
}

template<class T>
T CSNode<T>::getData()
{
	return data;
}

template<class T>
void CSNode<T>::setFirstChild(T newData)
{
	firstchild->data = newData;
}

template<class T>
void CSNode<T>::setNextsibling(T newData)
{
	nextsibling->data = newData;
}

//树类
template<class T>
class CSTree
{
public:
	CSTree();
	CSTree(const CSTree<T>& csTree);  //拷贝构造函数
	~CSTree();
	const CSTree<T>& operator=(const CSTree<T>& csTree);//重载赋值运算符
	void  createCSTree(); //按建立树
	void  InitCSTree();   //初始化树
	void  destoryCSTree();//销毁树
	bool  isEmptyCSTree();//检查树是否为空
	void  preOrderTraverse();//先序遍历
	void  postOrderTraverse(); //后序遍历
	void  levelOrderTraverse();//层序遍历
	int   heightCSTree();//树高度
	int   widthCSTree(); //树宽度
	int   getDegreeCSTree();//树的度--树中所有结点度的最大值
	int   nodeCountCSTree();  //树结点个数
	int   LeavesCountCSTree();//树叶子个数
	int   nodeLevelCSTree(T item);//结点item在的层次
	int   getChildrenCount(const CSNode<T>* p)const;//返回结点孩子个数
	void  getAllParentCSTree(T item)const;//找item的所有祖先
	void  longPathCSNode();//输出从每个叶子结点到根结点的最长路径 ----- 未实现
	bool  findCSNode(const T item,CSNode<T>*& ret)const; //查找结点
	bool  getParentCSTree(const T item,CSNode<T>*& ret)const;//查找结点item的父亲结点
	bool  getleftChild(const CSNode<T>* p,CSNode<T>*& ret) const; //返回最左边的兄弟
	bool  getrightSibling(const CSNode<T>* p,CSNode<T>*& ret) const; //返回最右边的兄弟
	bool  getAllSibling(const T item) const;//输出所有兄弟
	bool  getAllChildren(T item);//输出所有的孩子
private:
	void create(CSNode<T>*& p);//以p为根创建子树
	void  copyTree(CSNode<T>*& copyTreeRoot,CSNode<T>* otherTreeRoot);//把以otherTreeRoot为根节点的部分拷贝到copyTreeRoot为根节点的部分
	void  destory(CSNode<T>*& p,int& num);//销毁以p为根节点的部分
	void  preOrder(CSNode<T>* p);//先序遍历以p为根节点的部分
	void  postOrder(CSNode<T>* p);//后序遍历以p为根节点的部分
	void  levelOrder(CSNode<T>* p);//层次遍历以p为根节点的部分
	int   height(CSNode<T>* p);//计算以p为根节点的高度
	int   width(CSNode<T>* p);//计算以p为根子树的宽度
	int   nodeCount(CSNode<T>* p);//计算以p为根节点的结点个数
	int   leavesCount(CSNode<T>* p);//计算以p为根节点的叶子个数
	void  nodeLevel(T item,CSNode<T>* p,int level,int& nlevel);//计算以p为根节点的中item所在层次，如有多个元素，则遇到第一个则返回（离根最近），如果没有出现，则返回0
	bool  find(CSNode<T>*p,const T item,bool& isFind,CSNode<T>*& cur)const;//在p指向的树中，返回 值为item的指针
	bool  getParent(CSNode<T>*p,const T item,bool& isFind,bool& isFirst,CSNode<T>*& ret)const;//在p指向子树中，找item的父亲
	bool getAllParent(T item,CSNode<T>* p,CSNode<T>* path[MaxCSTreeSize],int& seat,bool& isFind)const;//找item的所有祖先，seat表示最后一个父亲的下标
	void  longPath(CSNode<T>* p,int len,int& maxLen,CSNode<T>*& longNode);//输出从每个叶子结点到根结点的最长路径
	int getDegree(CSNode<T>* p);//输出树的度（书中结点的孩子最大值）
private:
	CSNode<T>* root;
};

template<class T>
CSTree<T>::CSTree()
{
	root = NULL;
}

template<class T>
CSTree<T>::CSTree(const CSTree<T>& csTree)//拷贝构造函数
{
	if (csTree.root != NULL)
	{
		copyTree(root,csTree.root);
	}
	else
	{
		root = NULL;
	}
}

template<class T>
void  CSTree<T>::copyTree(CSNode<T>*& copyTreeRoot,CSNode<T>* otherTreeRoot)//把以otherTreeRoot为根节点的部分拷贝到copyTreeRoot为根节点的部分
{
	if (otherTreeRoot != NULL)
	{
		copyTreeRoot = new CSNode<T>;
		copyTreeRoot->data = otherTreeRoot->data;
		copyTree(copyTreeRoot->firstchild,otherTreeRoot->firstchild);
		copyTree(copyTreeRoot->nextsibling,otherTreeRoot->nextsibling);
	}
}

template<class T>
CSTree<T>::~CSTree() //析构函数 注意
{
	if(root != NULL)
	{
		int number = 0;//number记录被释放结点的个数，为了调试使用
		destory(root,number);
		InitCSTree();
	}
}

template<class T>
void  CSTree<T>::InitCSTree()   //初始化树
{
	root = NULL;
}

template<class T>
void  CSTree<T>::destory(CSNode<T>*& p,int& num)//销毁以p为根节点的部分
{
	if (p!=NULL)
	{
		destory(p->firstchild,num);
		destory(p->nextsibling,num);
		delete p;
		num++;
	}
}

template<class T>
void  CSTree<T>::destoryCSTree()//销毁树
{
	int number = 0;
	destory(root,number);
	root = NULL;
	cout<<"销毁了"<<number<<"个结点！"<<endl;
}

template<class T>
const CSTree<T>& CSTree<T>::operator=(const CSTree<T>& csTree)
{
	if (this!=&csTree)//避免自赋值
	{
		if (root!=NULL)//被赋值的对象不空，释放其资源
		{
			int number = 0;
            destory(root,number);
		}
		if (csTree.root != NULL)
		{
			copyTree(root,csTree.root);
		}
		else
		{
			root = NULL;
		}
	}
	return *this;
}

template<class T>
void  CSTree<T>::createCSTree() //
{
	create(root);
}

template<class T>
void CSTree<T>::create(CSNode<T>*& p)//以p为根创建子树 利用队列，整个过程中只入队，不出队列
{
   T parent;
   T child;

   //定义循环队列
   CSNode<T> *queue[MaxCSTreeSize];
   int front = 0;
   int rear = 0;

   CSNode<T> *current;
   cout<<"请输入父亲和孩子："<<endl;
   cin>>parent>>child;
   while(child != '#')//输入结束
   {
     CSNode<T> *newNode = new CSNode<T>;
	 newNode->data = child;
	 newNode->firstchild = NULL;
	 newNode->nextsibling = NULL;

	 if (parent == '#')//根结点
	 {
		 p = newNode;
         queue[(rear++)%MaxCSTreeSize] = p;//根入队列
	 }
	 else
	 {
         current = queue[front]; //读取队顶元素
		 while(current->data != parent)//在队列中查找父亲结点
		 {
			 front = (front+1)%MaxCSTreeSize;
			 current = queue[front];
		 }

		 if (current->data == parent)//对顶元素是当前新建结点的父亲
		 {
             if (current->firstchild == NULL)
             {
				 current->firstchild = newNode;
             }
			 else
			 {
                 current = current->firstchild;
				 while(current->nextsibling!=NULL)
				 {
					 current = current->nextsibling;
				 }
				 current->nextsibling = newNode;
			 }
		 }

		 if ((rear+1)%MaxCSTreeSize != front)//队列不满，将孩子入队列
		 {
			 queue[(rear++)%MaxCSTreeSize] = newNode;
		 }
	 }
	 cin>>parent>>child;
   }
}

template<class T>
bool  CSTree<T>::isEmptyCSTree()//检查树是否为空
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void  CSTree<T>::preOrderTraverse()//先序遍历
{
	preOrder(root);
}

template<class T>
void  CSTree<T>::preOrder(CSNode<T>* p)//树的先序遍历等价于cstree的先序遍历
{
	if (p!=NULL)
	{
		cout<<p->data<<" ";//cout<<p->getData()<<" ";
		preOrder(p->firstchild);
		preOrder(p->nextsibling);
	}
}

template<class T>
void  CSTree<T>::postOrderTraverse() //后序遍历
{
	postOrder(root);
}

template<class T>
void  CSTree<T>::postOrder(CSNode<T>* p)//树的后序遍历等价于cstree的中序遍历
{
	if (p!=NULL)
	{
		postOrder(p->firstchild);
		cout<<p->data<<" ";
		postOrder(p->nextsibling);
	}
}

template<class T>
void CSTree<T>::levelOrderTraverse()//层序遍历
{
	levelOrder(root);
}

template<class T>
void CSTree<T>::levelOrder(CSNode<T>* p)//层次遍历以p为根节点的部分
{//和二叉树的层序遍历一样
	//定义队列
	CSNode<T> *queue[MaxCSTreeSize];
	int front = 0;
	int rear = 0;

	CSNode<T> *current = p;
	queue[(rear++)%MaxCSTreeSize] = p;//根入队
	while(rear > front)
	{
		current = queue[(front++)%MaxCSTreeSize];//取出队顶元素
		cout<<current->data <<" ";
		if (current->firstchild!=NULL)
		{
			for (current=current->firstchild; current!=NULL; current=current->nextsibling)//孩子结点入队
			{
				queue[(rear++)%MaxCSTreeSize] = current;
			}
		}
	}
}

template<class T>
int CSTree<T>::heightCSTree()//树高度
{
	return height(root);
}

template<class T>
int CSTree<T>::height(CSNode<T>* p)//计算以p为根节点的高度
{
	int maxHeight = 0;
    if (p==NULL)//出口一
    {
        return 0;
    }

	if (p->firstchild == NULL)//出口二
	{
		return 1;
	}

	int max = 0;//max记录结点的孩子子树高度的最大值
	for (CSNode<T>* pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
	{
		int temp = height(pNode);
		if (temp > max)
		{
			max = temp;
		}
	}
	maxHeight = max+1;

	/*for (CSNode<T>* pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
	{
		int temp = height(pNode)+1;
		if (temp > maxHeight)
		{
			maxHeight = temp;
		}
	}*/
	return maxHeight;
}

template<class T>
int CSTree<T>::widthCSTree() //树宽度
{
	return width(root);
}

template<class T>
int  CSTree<T>::width(CSNode<T>* p)//计算以p为根子树的宽度
{//定义一般队列
	CSNode<T> *queue[MaxCSTreeSize];
	int front = 0;
	int rear = 0;

	CSNode<T> *current;
	int temWidth = 0;
	int maxWidth = 0;
	int last = 0;//记录每层最后一个元素的位置下标
	if (p!=NULL)
	{
		queue[rear] = p;//根入队列 rear指向最后一个元素
		while(last >= front)
		{
           current = queue[front++];//出队列
           temWidth++;//记录本层宽度

		   for (current=current->firstchild;current;current=current->nextsibling)//当前出队列元素的孩子全部入队列
		   {
			   queue[++rear] = current;
		   }

		   if (front > last)//上层出队列完毕
		   {
			   last = rear;//更新last
			   if (temWidth > maxWidth)
			   {
				   maxWidth = temWidth;//更新最大宽度
			   }
			   temWidth = 0;
		   }
		}
	}
	return maxWidth;
}

template<class T>
int CSTree<T>::getDegreeCSTree()//树的度--树中所有结点度的最大值
{
	return getDegree(root);
}

template<class T>
int CSTree<T>::getDegree(CSNode<T>* p)//输出树的度
{
	int degree = 0;
	if (p==NULL)
	{
		return 0;
	}
	if (p->firstchild == NULL)
	{
		return 1;
	}
	for (CSNode<T> *pNode=p->firstchild;pNode;pNode=pNode->nextsibling)//计算p的度
	{
        degree++;
	}
	for (CSNode<T> *pNode=p->firstchild;pNode;pNode=pNode->nextsibling)//计算p的所有孩子子树的度
	{
		int temDegree = getDegree(pNode);
		if (temDegree > degree)
		{
           degree = temDegree;
		}
	}
    return degree;
}

template<class T>
int CSTree<T>::nodeCountCSTree()  //树结点个数
{
	return nodeCount(root);
}

template<class T>
int   CSTree<T>::nodeCount(CSNode<T>* p)//计算以p为根节点的结点个数
{
	int count = 0;
	if (p == NULL)
	{
		return 0;
	}
	if (p->firstchild == NULL)
	{
		return 1;
	}
	for (CSNode<T>* pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
	{
        count += nodeCount(pNode);
	}
	return count+1;
}

template<class T>
int CSTree<T>::LeavesCountCSTree()//树叶子个数
{
	return leavesCount(root);
}

template<class T>
int CSTree<T>::leavesCount(CSNode<T>* p)//计算以p为根节点的叶子个数
{
	int leavecount = 0;
    if (p==NULL)
    {
		return 0;
    }
	if (p->firstchild == NULL)
	{
		return 1;
	}
	for (CSNode<T>* pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
	{
        leavecount += leavesCount(pNode);
	}
	return leavecount;
}

template<class T>
int CSTree<T>::nodeLevelCSTree(T item)//结点item在的层次
{
	int nlevel = 0;
	nodeLevel(item,root,1,nlevel);
	return nlevel;
}

template<class T>
void  CSTree<T>::nodeLevel(T item,CSNode<T>* p,int level,int& nlevel)//计算以p为根节点的中item所在层次，如有多个元素，则遇到第一个则返回（离根最近），如果没有出现，则返回0
{//level记录当前已经查到第几层
   if (p==NULL)
   {
	   return;
   }
   //if (nlevel)//nlevel不为0,表示已经找到   此步需要吗？经检验不需要
   //{
	  // return;
   //}
   if (p->data == item)
   {
	   nlevel = level;
	   return;
   }
   for (CSNode<T> *pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
   {
	   nodeLevel(item,pNode,level+1,nlevel);
   }
}

template<class T>
int CSTree<T>::getChildrenCount(const CSNode<T>* p)const//返回结点孩子个数
{
	int count = 0;
	if (p!=NULL)
	{
		if (p->firstchild == NULL)
		{
			return 0;
		}
		else
		{
			for (CSNode<T> *pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
			{
                count++;
			}
		}
	}
	return count;
}

template<class T>
void  CSTree<T>::getAllParentCSTree(T item)const//找item的所有祖先
{
	CSNode<T> *path[MaxCSTreeSize];
	int len = 0;
	bool isFind = false;
	getAllParent(item,root,path,len,isFind);
	cout<<item<<"的所有祖先：";
	for (int i=0;i<len;i++)
	{
		cout<<path[i]->data<<" ";
	}
	cout<<endl;
}

/*思想:
使用一个数组保存双亲结点
双亲放入数组，之后当处理检查完自己和左子树的时候，如果没找到，则这个结点就不会再是其双亲结点，直接把该结点移除数组。
*/
template<class T>
bool CSTree<T>::getAllParent(T item,CSNode<T>* p,CSNode<T>* path[MaxCSTreeSize],int& len,bool& isFind)const//找item的所有祖先，seat表示最后一个父亲的下标
{//好好考虑，与二叉树比较
     if (isFind)
     {
		 return isFind;
     }
	 if (p==NULL)
	 {
		 return false;
	 }
	 if (p->data == item)
	 {
		 isFind = true;
		 return isFind;
	 }
	 else
	 {
		 path[len++] = p;//没有找到，将访问的结点放入path数组中，有待剔除一些结点
		 getAllParent(item,p->firstchild,path,len,isFind);
		 if (!isFind)
		 {
			 len = len-1;
			 getAllParent(item,p->nextsibling,path,len,isFind);
		 }
	 }
	 return isFind;
}

template<class T>
void  CSTree<T>::longPathCSNode()//输出从每个叶子结点到根结点的最长路径 ----- 未实现
{
	int len = 0;
	int maxlen = 0;
	CSNode<T> *longNode;
	longPath(root,len,maxlen,longNode);
}

template<class T>
void  CSTree<T>::longPath(CSNode<T>* p,int len,int& maxLen,CSNode<T>*& longNode)//输出从每个叶子结点到根结点的最长路径
{//思想：
  //未实现
}

template<class T>
bool  CSTree<T>::findCSNode(const T item,CSNode<T>*& ret)const //查找结点
{
	bool isFind = false;
	find(root,item,isFind,ret);
	return isFind;
}

template<class T>
bool  CSTree<T>::find(CSNode<T>*p,const T item,bool& isFind,CSNode<T>*& cur)const//在p指向的树中,返回值为item的指针
{
	if (isFind)//出口一
	{
		return isFind;
	}
	if (p==NULL)//出口二
	{
		cur = NULL;
		return isFind;
	}
	if (p->data == item)//出口三
	{
		cur = p;
		isFind = true;
		return isFind;
	}
	else
	{
		for (CSNode<T> *pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
		{
			find(pNode,item,isFind,cur);
			if (isFind)//找到即返回
			{
				return isFind;
			}
		}
	}
	return isFind;
}

template<class T>
bool  CSTree<T>::getParentCSTree(const T item,CSNode<T>*& ret)const//查找结点item的父亲结点
{
	bool isFind = false;
	bool isFirst = true;
	getParent(root,item,isFind,isFirst,ret);
	return isFind;
}

template<class T>
bool  CSTree<T>::getParent(CSNode<T>*p,const T item,bool& isFind,bool& isFirst,CSNode<T>*& ret)const
{//需要好好理解
   if (isFind)
   {
	   return isFind;
   }
   if (p==NULL)
   {
	   return false;
   }
   if (p->data == item)
   {
	   if (p == root)
	   {
		   cout<<"该元素是根结点，没有父亲！"<<endl;
		   isFind = false;
		   return isFind;
	   }
	   else
	   {
		   isFind = true;//此处不能给ret赋值，只能在递归出去后才能继续得到父亲的指针
		   return isFind;
	   }
   }
   for (CSNode<T> *pNode=p->firstchild;pNode;pNode=pNode->nextsibling)
   {
	   getParent(pNode,item,isFind,isFirst,ret);
	   if (isFind&&isFirst)
		   //检查递归回来的结果，如果找到，就为ret赋值，因为递归在回退的时候，isFind仍也是true，
		   //不引入isFirst就还会对结点ret赋值，即一路回退一路赋值。
		   //如果要避免这种情况，则需要引入这个变量，只有第一次出现这个情况的时候才为其赋值
	   {
		   isFirst = false;
		   ret = p;
		   return isFind;
	   }

   }
   return isFind;
}

template<class T>
bool  CSTree<T>::getleftChild(const CSNode<T>* p,CSNode<T>*& ret) const   //返回最左边的兄弟
{
	if (p==NULL)
	{
		return false;
	}
	else
	{
		if (getParentCSTree(p->data,ret))
		{
			ret = ret->firstchild;
			return true;
		}
		else
		{
			return false;
		}
	}
}

template<class T>
bool  CSTree<T>::getrightSibling(const CSNode<T>* p,CSNode<T>*& ret) const //返回最右边的兄弟
{
	if (p==NULL)
	{
		return false;
	}
	else
	{
		if (getParentCSTree(p->data,ret))
		{
			CSNode<T> *node = ret->firstchild;
			while(node->nextsibling)
			{
				node = node->nextsibling;
			}
			ret = node;
			return true;
		}
		else
		{
			return false;
		}
	}
}

template<class T>
bool  CSTree<T>::getAllSibling(const T item) const //输出所有兄弟
{
	bool isFind = false;
	CSNode<T> *ret = NULL;
	isFind = getParentCSTree(item,ret);
	if (!isFind)
	{
		return false;
	}
	else
	{
		isFind = false;
		cout<<item<<"的所有兄弟：";
		for (CSNode<T> *pNode=ret->firstchild;pNode;pNode=pNode->nextsibling)
		{
			if (pNode->data != item)
			{
				isFind = true;
				cout<<pNode->data<<" ";
			}
		}
		cout<<endl;
		return isFind;
	}

}

template<class T>
bool  CSTree<T>::getAllChildren(T item)//输出所有的孩子
{
	CSNode<T> *ret = NULL;
	bool isFind = false;
	findCSNode(item,ret);

	cout<<item<<"的所有孩子：";
	for(CSNode<T> *pNode=ret->firstchild;pNode;pNode=pNode->nextsibling)
	{
		isFind = true;
        cout<<pNode->data<<" ";
	}
	cout<<endl;

	return isFind;
}

int main()
{
	CSTree<char> tree;
	tree.createCSTree();
	cout<<"树的先序遍历：";
	tree.preOrderTraverse();
	cout<<endl;
	cout<<"树的后序遍历：";
	tree.postOrderTraverse();
	cout<<endl;
    cout<<"树的层序遍历：";
	tree.levelOrderTraverse();
	cout<<endl;
	cout<<"树的高度："<<tree.heightCSTree()<<endl;
	cout<<"树的宽度："<<tree.widthCSTree()<<endl;
    cout<<"树的结点个数："<<tree.nodeCountCSTree()<<endl;
	cout<<"树的叶子结点的个数："<<tree.LeavesCountCSTree()<<endl;
	cout<<"树的度："<<tree.getDegreeCSTree()<<endl;
    cout<<"F在树中的层数："<<tree.nodeLevelCSTree('F')<<endl;
	tree.getAllParentCSTree('K');
	cout<<endl;
	CSNode<char>* ret;
    if (tree.findCSNode('H',ret))
    {
		cout<<ret->data<<"的父亲结点：";
    }
	CSNode<char>* parent;
    tree.getParentCSTree(ret->data,parent);
	cout<<parent->data<<endl;
	return 0;
}

// Node* helper(Node*root,unordered_map<Node*,Node*>&parentMap,int target){
        
//         //we use level order traversal for parent mapping and target node finding
//         queue<Node*>q;
//         Node* targetNode = NULL;
//         q.push(root);
//         parentMap[root]=NULL;
        
//         while(!q.empty())
//         {
//             Node* front = q.front(); q.pop();
            
//             if(front->data == target)
//             {
//                 targetNode = front;
//             }
            
//             if(front->left)
//             {
//                 q.push(front->left);
//                 parentMap[front->left]=front;
//             }
            
            
//             if(front->right)
//             {
//                 q.push(front->right);
//                 parentMap[front->right]=front;
//             }
            
//         }
        
//         return targetNode;
        
        
//     }
    
//     int burnTheTree(Node*targetNode,unordered_map<Node*,Node*> &parentMap){
        
//         unordered_map<Node*,bool>isBurnt;
//         queue<Node*>q;
//         int T =0;
        
//         q.push(targetNode);
//         isBurnt[targetNode]=true;
        
//         while(!q.empty())
//         {
//             int size = q.size();
//             bool isFireSpread = false;
            
//             for(int i=0;i<size;i++){
//                 Node* front = q.front();
//                 q.pop();
                
//                 if(front->left and !isBurnt[front->left])
//                 {
//                     q.push(front->left);
//                     isBurnt[front->left]=true;
//                     isFireSpread = true;
//                 }
                
                
//                 if(front->right and !isBurnt[front->right])
//                 {
//                     q.push(front->right);
//                     isBurnt[front->right]=true;
//                     isFireSpread = true;
//                 }
                
//                 if(parentMap[front] and !isBurnt[parentMap[front]])
//                 {
//                     q.push(parentMap[front]);
//                     isBurnt[parentMap[front]] = true;
//                     isFireSpread=true;
//                 }
//             }
            
//             if(isFireSpread){
//                 T++;
//             }
//         }
        
//         return T;
        
//     }
    
//     int minTime(Node* root, int target) 
//     {
//         // Your code goes here
//         unordered_map<Node*,Node*>parentMap;
//         Node* targetNode = helper(root,parentMap,target);
//         return burnTheTree(targetNode,parentMap);
//     }
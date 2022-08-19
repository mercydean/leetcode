# The purpose of the leetcode

## study and practice DS&amp;ALGO

- link list

- tree

- array

- sort algorithms

- 《算法竞赛进阶指南》，《算法导论》《算法 4》和 liuyubobobo 算法课程，在学习算法与数据结构的道路上，都发挥了巨大的作用。

## study and practice git

Overall, newbies please see [Github guide](https://www.runoob.com/w3cnote/git-guide.html)to build an overall picture.

- get and set the SSH public key and private key. see [connecting-to-github-with-ssh](https://docs.github.com/cn/authentication/connecting-to-github-with-ssh) for more details. Mainly used for authentication.

- create a local repo: 
  
  - `git init ` (current directory used as the local repo)

- link a remote repo:
  
  - only a existed repo can link.
  
  - `git remote add origin git@github.com:mercydean/leetcode.git`

- `git fetch` + `git merge` / `git pull`

- do some stuff here
  
  - modify files in the workspace(working directory)
  
  - `git add <file_name>`
  
  - `git rm -r --cached <file_name> `
  
  - `git commit -m 'message'`
  
  - delete the commit: `git reset --soft HEAD^`
    
    - -soft不删除工作空间改动代码，撤销commit，不撤销git add.
    
    - HEAD^的意思是上一个版本，也可以写成HEAD~1
      
      如果你进行了2次commit，想都撤回，可以使用HEAD~2-

- `git push -u origin master`

- see [Git tutorial](https://www.runoob.com/git/git-tutorial.html) for more details

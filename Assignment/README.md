# 作業導覽 (Assignment Navigation)

以下是本學期的五項核心作業簡介，可以點擊標題連結至詳細的學習紀錄：

### [Assignment I：GitHub 初次建立與使用](./Assignment_I_README.md)

* **核心目標**：建立專業的開發環境與個人展示窗口。
  
* **完成重點**：
  
    * 建立課程專屬儲存庫與個人靜態網頁（GitHub Pages）。
      
    * 掌握 Markdown 語法撰寫技術文件。

### [Assignment II：陣列與選擇排序法](./Assignment_II_README.md)

* **核心目標**：實作基礎陣列操作與排序演算法流程。
  
* **完成重點**：
  
    * 視覺化陣列結構與索引配置（Index 0-7）。
      
    * 手寫追蹤選擇排序法（Selection Sort）的前三步運算。
      
    * 分析 $O(n^2)$ 時間複雜度與 $O(1)$ 空間複雜度的特性。

### [Assignment III：鏈結串列與選擇排序法](./Assignment_III_README.md)

* **核心目標**：透過實作比較線性資料結構（陣列 vs. 串列）的效能與權衡。
  
* **完成重點**：
  
    * 實作單向鏈結串列（Singly Linked List）的節點導航。
      
    * 在串列上執行「交換節點值」的排序邏輯。
      
    * 深度討論陣列隨機存取與串列循序存取（Traversal）的效能差異。

### [Assignment IV：雜湊函數設計與觀察 (Hash Function Design & Observation)](./Assignment_IV_README.md)

* **核心目標**：針對整數與字串設計高效雜湊函數，並觀察不同雜湊表大小（$m$）對碰撞（Collision）的影響。
  
* **完成重點**：
  
    * **整數雜湊**：採用乘法取模法（Multiplication Method），利用黃金比例常數 $A \approx 0.618$ 優化分布。
      
    * **字串雜湊**：實作多項式滾動雜湊（Polynomial Rolling Hash），以質數 31 作為基底（$p$）權重。
      
    * **對比分析**：實驗 $m=10, 11, 37$ 三種規模，發現乘法取模法受「表大小」的影響顯著大於「是否為質數」。
      
    * **技術實踐**：同步提供 C23 與 C++23 版本，並透過 Makefile 自動化建置。

### [Assignment V：樹狀結構之家族層級、建置與應用](./Assignment_V_README.md)

* **核心目標**：探索樹狀結構的演化 path 與現實世界應用。
  
* **完成重點**：
  
    * 定義並區分八種樹狀變體（BST, AVL, Heap, Red-Black 等）。
      
    * 建立樹狀家族層級圖，解釋從一般樹到平衡樹的約束演化。
      
    * 實作堆積（Heap）與平衡搜尋樹的建置，並分析其在資料庫索引與行程排程中的應用。
      
    * 實踐 AI 協作學習模式，利用 AI 工具進行定義複習與效能比較。

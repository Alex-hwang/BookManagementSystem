# -*- coding: gbk -*-
import sys
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

def draw_chart(users, borrow_counts):
    # 计算平均借阅数量
    average_borrow = sum(borrow_counts) / len(borrow_counts)
    
    # 创建一个图形窗口，并分为1行2列的子图
    fig, axs = plt.subplots(1, 2, figsize=(16, 6))
    
    # 第一个子图：条形图
    axs[0].bar(users, borrow_counts, color='skyblue')
    axs[0].set_xlabel('用户')
    axs[0].set_ylabel('借阅数量')
    axs[0].set_title('用户借阅数量图表')
    axs[0].tick_params(axis='x', rotation=45)
    axs[0].grid(axis='y', linestyle='--', alpha=0.7)
    axs[0].yaxis.set_major_locator(ticker.MaxNLocator(integer=True))
    axs[0].axhline(average_borrow, color='r', linestyle='--', label=f'平均借阅数量: {average_borrow:.2f}')
    axs[0].legend()
    
    # 在条形图的每个条形上添加数据标签
    for i, count in enumerate(borrow_counts):
        axs[0].text(i, count + count * 0.05, str(count), ha='center', va='bottom')
    
    # 第二个子图：饼图
    axs[1].pie(borrow_counts, labels=users, autopct='%1.1f%%', startangle=140)
    axs[1].set_title('每个用户在总借阅量中的占比')
    
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    args = sys.argv[1:]
    users = args[0::2]
    borrow_counts = [int(count) for count in args[1::2]]

    draw_chart(users, borrow_counts)

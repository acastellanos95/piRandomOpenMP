import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
sns.set_theme(style="whitegrid")

# plot seq

# seqdata = pd.read_csv("./resultadosseq.data", " ", header=0)
# print(seqdata)
# plotseq = sns.lineplot(x=seqdata['ITERATIONS'],y=seqdata['SEQTIME'])
# # seqdata.plot.line()
# plt.savefig("seqtime.png")

# plot par
# data = pd.read_csv("./resultadospar.data", " ", header=0)
#
# data = data[['ITERATIONS', 'THREADS', 'PARTIME']]
# Matrix_Size_Order = data['ITERATIONS']
# data_wide = data.pivot_table(index='THREADS', columns='ITERATIONS', values=['PARTIME'])
# # data_wide = data_wide.reindex(Matrix_Size_Order, axis=0)
# print(data_wide)
#
# plot = sns.lineplot(data=data_wide['PARTIME'])
# plt.savefig("partime.png")

# plot pi

# data = pd.read_csv("./pi.data", " ", header=0)
#
# data = data[['ITERATIONS', 'THREADS', 'PI']]
# Matrix_Size_Order = data['ITERATIONS']
# data_wide = data.pivot_table(index='THREADS', columns='ITERATIONS', values=['PI'])
# # data_wide = data_wide.reindex(Matrix_Size_Order, axis=0)
# print(data_wide)
#
# plot = sns.scatterplot(data=data_wide['PI'])
# plt.savefig("pivalues.png")

# plot accelerations

data = pd.read_csv("./aceleracion.data", " ", header=0)

data = data[['ITERATIONS', 'THREADS', 'ACC']]
Matrix_Size_Order = data['ITERATIONS']
data_wide = data.pivot_table(index='THREADS', columns='ITERATIONS', values=['ACC'])
# data_wide = data_wide.reindex(Matrix_Size_Order, axis=0)
print(data_wide)

plot = sns.lineplot(data=data_wide['ACC'])
plt.savefig("acc.png")
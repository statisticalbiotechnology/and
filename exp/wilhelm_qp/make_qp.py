import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
sns.set_style("whitegrid")

p="Millions of PSMs"
q="$q$ value"

# Load data from tab delimeted file
pq = pd.read_csv("q_p_100k", sep='\t', names=[p, q], header=0, index_col=False)
pqp = pd.read_csv("q_psms_100k", sep='\t', names=[p, q], header=0, index_col=False)

pq["Method"]="Crux p-value"
pqp["Method"]="Percolator"

pq = pqp.append(pq, ignore_index=True)
pq[p] = pq[p]/1000000

fig, ax = plt.subplots()
# the size of A4 paper
fig.set_size_inches(7, 4)

# Plot the responses for different events and regions
fig = sns.lineplot(y=p, x=q,
            # kind="line",
            linewidth=4,
            hue="Method",
            legend="full",
#             hue="region", style="event",
             data=pq, ax=ax)
sns.despine()
plt.xlim(-0.001,0.03)
#plt.ylim(0,0.6e8)
plt.ylim(0,0.6e2)
plt.legend(loc='lower right')
plt.savefig("q_p.png")

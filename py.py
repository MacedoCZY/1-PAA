import matplotlib.pyplot as plt


plt.figure(figsize=(10,7.5))

# Crie um vetor de dados para o eixo x
x_data = [100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000]
# Crie quatro vetores de dados para o eixo y
y_data_aleatorio = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 11, 65, 430, 1006, 1831, 2919, 4181, 7381]
y_data_ordenados = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 4, 22, 145, 328, 599, 917, 1384, 2369]
y_data_decrescentes = [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 7, 14, 57, 351, 795, 1401, 2177, 3153, 5607]
y_data_parcialmente_ordenados = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 22, 134, 328, 577, 917, 1384, 2362]

y_data_aleatorio_flag = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 10, 62, 441, 1003, 1882, 2882, 4097, 7274]
y_data_ordenados_flag = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
y_data_decrescentes_flag = [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 7, 12, 52, 325, 733, 1400, 2154, 3150, 5567]
y_data_parcialmente_ordenados_flag = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 8, 12, 16, 16, 18]

# Crie um gráfico de linhas com quatro linhas
#plt.plot(x_data, y_data_aleatorio, label="Aleatório")
#plt.plot(x_data, y_data_ordenados, label="Ordenados")
plt.plot(x_data, y_data_decrescentes, label="Decrescentes")
#plt.plot(x_data, y_data_parcialmente_ordenados, label="Parcialmente ordenados")
#plt.plot(x_data, y_data_aleatorio_flag, label="Aleatório com Flag")
#plt.plot(x_data, y_data_ordenados_flag, label="Ordenados com Flag")
plt.plot(x_data, y_data_decrescentes_flag, label="Decrescentes com Flag")
#plt.plot(x_data, y_data_parcialmente_ordenados_flag, label="Parcialmente ordenados com Flag")
plt.xticks(x_data, rotation=90)
plt.tight_layout()

# Configure o label do eixo x
plt.xlabel("Tamanho do vetor Ordenado(Potência de 10^6)")

# Configure o label do eixo y
plt.ylabel("Tempo de execução em Segundos")

plt.xlim(x_data[0], x_data[-1])
plt.subplots_adjust(left=0.08, right=0.992, top=0.992, bottom=0.1)
# Configure as cores das linhas
#plt.legend(loc="upper left", colors=["red", "green", "blue", "yellow"])




# Mostre o gráfico
plt.legend()
plt.show()
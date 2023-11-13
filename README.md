# Лабораторная работа №1
В ходе лабораторной работы были реализованы 3 алгоритма поиска элемента в матрице (Ladder search, Binary search, Exponencial + Ladder search) и две генерации данных для матрицы (линейная и экспоненциальная). Код был написан на С++ и запускался в Visual Studio. Файлы для запуска прикреплены.

Код содержит ряд фунций:
~~~
first_matrix_generation() - заполнение матрицы согласно линейной генерации данных

second_matrix_generation() - заполнение матрицы согласно экспоненциальной генерации данных 

ladder_search() - лестничный поиск. O(M+N)

binary_search() - бинарный поиск. O(MlogN)

exp_lad_search() - экспоненциальный поиск. O(M(LogN - LogM + 1))

ladder_search_test() - тесты лестничного поиска

binary_search_test() - тесты бинарного поиска

exp_lad_search_test() - тесты экспоненциального поиска с лестничной оптимизацией
~~~
**Генерация данных выбирается вручную при запуске кода.**

Результаты запусков и графики можно найти по ссылке: https://docs.google.com/spreadsheets/d/1dbpvRcXpxakb9oCqXL3uV4Sf6HTs1GVF_ioQH_Y4RfE/edit?usp=sharing

## Выводы

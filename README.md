# Репозиторий программы 6-го задания

## Условие
Условие задания можно найти на странице https://contest.solutions/msu/106/6.html. 
Требуется с точностью 0.001 подсчитать лощадь плоской фигуры, ограниченной тремя кривыми, заданными как графики данных функций. Для этого требется реализовать численные методы нахождения корней уравнения и определённых интегралов.

## Сборка
Программа собирается при помощи GNU make, командой make all.

## Возможности

### Функции
Программа имеет набор остатически заданных функций. Их список можно посмотреть вызвав её с флагом -list. Первые три функции взяты из условия задания, остальные - дополнительные для проверки вычислительных методов.

### Вычисление в точке
Каждую из функций можно вычислить в произвольной точке при помощи флага -compute.

### Площадь
При запуске программы без параметров она считает площадь фигуры, описанной в тексте задания.

### Определённый интеграл
Для каждой из функций можно посчитать определённый интеграл на произвольном отрезке при помощи флага -integral. 

### Пересечение графиков 
Можно найти пересечение графиков любых  из функций при помощи флага -root, но стоит помнить, что для этого нужно, чтобы у функции (f(x) - g(x)) первая и вторая производные не меняли знак на отрезке, где ищется пересечение. 

### Количество шагов
Можно узнать количество шагов за которое программа посчитала точку пересечения или интеграл, дабавив флаг -steps после флага -root или -integral. Под шагом при поиске пересечния понимается применение метода хорд или метода касательных. Под шагом при подсчёте интеграла понимается подсчёт приближения интегральной суммы.

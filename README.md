# Calculadora Simples em C

Uma aplicação de consola desenvolvida na linguagem C que permite efetuar operações aritméticas básicas de forma interativa. O programa conta com validação de entradas, tratamento de erros (como divisão por zero) e compatibilidade multiplataforma para limpeza de ecrã.

---

## 🚀 Funcionalidades

* **Operações Básicas:**
  * Adição (`+`)
  * Subtração (`-`)
  * Multiplicação (`*`)
  * Divisão (`/`)
* **Tratamento de Erros:** Deteção e prevenção de divisão por zero, notificando o utilizador sem fechar o programa abruptamente.
* **Menu Interativo:** Permite realizar várias operações sucessivas ou sair de forma limpa.
* **Compatibilidade Multiplataforma:** Limpeza automática do ecrã compatível com sistemas **Windows** (`cls`) e **Linux/macOS** (`clear`).

---

## 🛠️ Tecnologias Utilizadas

* Linguagem **C** (padrão C99 ou superior).
* Bibliotecas standard: `<stdio.h>` e `<stdlib.h>`.

---

## ⚙️ Pré-requisitos

Para compilar e executar este programa, necessita de ter instalado no seu computador:
* Um compilador de C (por exemplo, **GCC**, **Clang** ou **MinGW**).

---

## 📥 Como Compilar e Executar

1. Guarde o código-fonte num ficheiro com o nome `calculadora.c`.
2. Abra a consola (terminal) na pasta onde guardou o ficheiro.
3. Compile o programa com o comando:
   ```bash
   gcc calculadora.c -o calculadora

## Overview
生成に関するデザインパターンを説明する

## Singleton
### 特徴
- クラスが一つのインスタンスのみを持つことを保証する
- 唯一のインスタンスへの大域アクセスポイントを提供する

### 問題点
singletonパターンは単一責任の原則に違反する

### 解決策
- 他のオブジェクトがsingletonクラスのnew演算子を使用しないようにデフォルトコンストラクタを非公開にする
- コンストラクタとして機能する静的メソッドを作成する。このメソッドの内部で非公開コンストラクタを呼び出して静的なフィールドに保存する。

### 参照
Singleton:
https://refactoring.guru/ja/design-patterns/singleton

SingletonをC++で:
https://refactoring.guru/ja/design-patterns/singleton/cpp/example


## Factory Method
### 特徴
- スーパークラスでオブジェクトのインターフェースを決定
- サブクラスでクラスの型を変更する
- Creator, Productのフーパクラスが存在し、CreatorがProductを生成する

### 問題
型が同じだが違うクラスで定義たいもの、例えば陸路と海路などの輸送方法をCreatorクラスとして、陸路ならトラック、海路なら船を定義するのがProductクラス

### 参照
Factory method:
https://refactoring.guru/ja/design-patterns/factory-method


## Abstract Factory
### 特徴
- 複数のスーパークラスを一つのまとまりとして、まとまりごとのサブクラスを生成する

### 参照
Abstract Factory:
https://refactoring.guru/ja/design-patterns/abstract-factory


## Prototype
### 特徴
既存のオブジェクトのコピーをそのクラスに依存することなく作成する

### 問題
オブジェクトの非公開部分含めた正確なコピーをすることが難しい

### 解決策
クローンされるオブジェクトにクローンメソッドが任される。自身をクローンメソッドで複製する。
クローンんをサポートする全てのオブジェクトに共通するインターフェースを宣言して、
オブジェクトを格納し、指定された場合にオブジェクトのクローンメソッドを実行する。

### 参考
Prototype:
https://refactoring.guru/ja/design-patterns/prototype


## Builder
### 特徴
複雑なオブジェクトを段階的に生成できる。

### 問題
多くの入れ子になったオブジェクトから構成され、面倒な段階的初期化が必要な複雑なオブジェクトを作成するのが大変

### 解決策
プロダクトはプロダクトリストを持ち、ビルダーが部品を生成してプロダクトリストに格納する。ディレクタは決められた最終製品に必要な部品群を生成するメソッドをあらかじめ持っており、このメソッドでプロダクトを作成する

### 参考
Builder:
https://refactoring.guru/ja/design-patterns/builder

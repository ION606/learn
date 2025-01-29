## A note:
my server crashed towards the end of the year, so most of the images are gone. I apologize for the inconvenience.

::: info
[Course Home](https://www.cs.rpi.edu/academics/courses/fall24/csci4380/)

[Course Notes](https://www.cs.rpi.edu/academics/courses/fall24/csci4380/fall2024/course_notes/intro.html#course-notes)

[Course Recordings](https://mediasite.mms.rpi.edu/mediasite/Channel/c625d7df57dc414d829c7b7b587f5c265f)

:::

### Terminology

- Database Management Systems (DBMS) - a software tool for storing/managing large amounts of data
- Database Server - a specific installation of a DBMS
- Database - a collection of data (often in a DBMS) organized for a specific application (also see [Database Section](https://cloud.ion606.com/apps/files/files#h-databases))
- Database Application - a software product that uses DBMSs to store one or more databases for a specific purpose
- Database Schema 
  - what types of data are valid to store
  - fixed model
  - Hard/expensive to change once implemented
  - Does NOT contain the data itself
  - **attributes are just the column names**
- Database Instance - 
  - the actual data that satisfies the rules of the database schema
  - changing facts, what is true about the data at the moment
- Relational Data Model - the most popular way to describe data schema
- Data Model 
  - the type of data that can be stored
  - rules about the data (Database Schema)
  - design so that you hopefully never have to make changes, cause making changes later on is difficult
- Transaction - a program that changes data or a sequence of database operations that satisfies the ACID properties (which can be perceived as a single logical operation on the data)
- ACID - see [ACID Section](https://cloud.ion606.com/apps/files/files/34361?dir=/School/Senior%20Year/Datbase%20Systems&openfile=true#h-a-c-i-d)
- Relational Data Model - see [Relational Data Model](https://cloud.ion606.com/apps/files/files/34361?dir=/School/Senior%20Year/Datbase%20Systems&openfile=true#h-relational-data-model) section
- Key - some attribute that determines other keys, you can have multiple keys
- minimal key - the minimum set of attributes needed to get the correct info
- super key - any superset containing the minimal key (any superset of the minimal key)
- Data: actual information/facts satisfying data model
- Tuple: A set of attributes and a value of each attribute
- Relational Database: 
  - A set of relations: 
    - A relation: A class of objects we want to store information about 
      - Relation instances contain sets of tuples, each tuple is an object of this class
- Database 
  - Database Schema + Database Instance + Application Logic
  - Relational Data Model
  - set of relations
- BCNF - see [BCNF](https://cloud.ion606.com/apps/files/files/34361?dir=/School/Senior%20Year/Datbase%20Systems&openfile=true#h-boyce-codd-normal-form-bcnf) section
- Entity-Relationship Models - See [ER](https://cloud.ion606.com/apps/files/files/34361?dir=/School/Senior%20Year/Datbase%20Systems&openfile=true#h-entity-relationship-models-er) section

### What Makes a DBMS

1. data model
2. store massive amounts of data
3. query language - allow access (read/write/update) to stored data easily
4. durability - data is safe even after something like a power outage
5. concurrent access - multiple users can read/write the same data without compromising integrity

### DBMS Components

- Storage Manager 
  - index or file manager
- Database Language Tools 
  - DML - Data query or manipulation language compiler
  - DDL - Data definition language
- Query Execution Engine 
  - Buffer Manager
- Transaction Manager 
  - Logging and Recovery
  - Concurrency Control
- Database Admin 
  - responsible for designing the data model
- Database Programmer 
  - responsible for writing application software that stores the database
- Systems Admin 
  - responsible for installation and tuning the DBMS system

### A C I D

a set of properties of database transactions intended to guarantee data validity despite errors, power failures, etc.

**__ACID stands for:__**

- Atomicity - transactions must be completed fully or leave no effect on the database
- Consistency - DBMS must not allow programmers to violate consistency rules for a database schema
- Isolation - multiple transactions executed at the same time should result in the same thing as executing them one at a time
- Durability - once a transaction completes, DBMS must record ALL its results and make sure they're not lost

::: info
Example: A transfer of funds from one bank account to another, even involving multiple changes such as debiting one account and crediting another, is a single transaction

:::

### Databases

- given by data schema/model (rules regarding data) and the database instance (the data)
- more here later.....

### Data Model

- Logical Data Model 
  - Relations and attributes
  - Constraints (what is valid data and what is not)
  - relation, tuple, attribute
- Physical Data Model 
  - Where to store the data 
    - which file systems (distributed, replicated)
  - How to store the data 
    - which indices to create
  - table, row, column
- Application Logic 
  - Built on top of database queries
  - declarative: write once and optimize on top of the logical data model

## Relational Data Model

**Definitions**

- Relations (or tables) - store information
- Attribute (or column) - a property of a specific object represented by a relation
- Domain - a set of valid input 
  - Simple domains are integers/strings
  - Complex Domains: 
    - can be defined with restrictions over these domains
    - example: an 8-digit integer that starts with 6
- Schema - the names/domains of/for the attributes

**Structure**

- A relation contains a set of tuples
- A valid relation instance is made of tuples containing: 
  - values for all attributes in the relation schema that are drawn from the domain with that attribute

**Logical vs Physical Names**

- Logical 
  - the mathematical definition of the relational data model
  - based on a set of semantics
- Physical 
  - the storage/implementation of the data model
  - the implementation might not be identical to the logical model

#### **Example Relations and Representations**

__TABLE__

__LOGICAL RERESENTATION (TUPLES)__

```SQL
Hero('Black Panther', 'T''Challa')
Hero('Flash', 'Barry Allen')
Hero('Jessica Jones', 'Jessica Jones')
```

__LOGICAL REPRESENTATION (SET)__

```set
Hero = { <'Black Panther':Alias, 'T''Challa':Name>,
         <'Flash':Alias, 'Barry Allen':Name>,
         <'Jessica Jones':Alias, 'Jessica Jones':Name> }
```

### Rules of Relational Data Models

- domain attributes MUST be simple 
  - integer
  - float
  - decimal
  - string
  - boolean
  - date
  - time
  - timestamp
  - restrictions of these (9-digit integer) 
    - restrictions are called the first normal form (1NF)
    - attributes are indivisible pieces of info (not lists or sets for example)
    - relations are flat pieces of information

### 

Relational Data Model

Each attribute comes with a domain: set of valid values: integer, boolean, string, date/time

A relation is a set of tuples, tuples are a set of attributes

#### Example 1:

Relations: Books

Tuple: A single book Attributes: isbn(string), title(string), author(string), price(money), publisher(string),

The order of things in attributes doesn’t matter, cause sets don’t have order

Books(‘14236-7788’, ‘War and Peace’, ‘Leo Tolstoy’, 24.99, ‘Pearson')

Books(‘1453456-999’, ‘Crime and Punishment’, ‘Dostoyevsky’, 4.99, ‘Pearson')

| isbn        | title                | author      | price | publisher |
|-------------|----------------------|-------------|-------|-----------|
| 14236-7788  | War and Peace        | Leo Tolstoy | 24.99 | Pearson   |
| 1453456-999 | Crime and Punishment | Dostoyevsky | 4.99  | Pearson   |

**A minimal key would be \[title, author\]**

#### Example 2:

R1 = { t1, t2, t3 }

R2 = { t1, t2, t3, t4 }

R1 and R2 are the same relation A key would be \[title, author\]

### Projection

syntax: `project_{property}{set}`

### Selection

![Selection.png](.attachments.34361/image.png)

### Cartesian Product

R x S = { t such that t has all attributes in R and all the attributes in S, such that there is a tuple r in R and a tuple s in S where t is equal to r for attributes in R and to s for attributes in S

R(A, B) = {<a1, b1>, <a2, b2>}

S(C, D) = {<c1, d1>, <c2, b2>, <c3, d3>}

T = R x S

T(A, B, C, D) = {<a1, b1, c1, d1>, <a1, b1, c2, d2>, <a1, b1, c3, d3>, <a2, b2, c1, d1>, <a2, b2, c2, d2>, <a2, b2, c3, d3>}

### Theta Join

R Join\_{C} S = { all tuples in R x S that satisfy join condition C }

A join condition C is a condition that refers to comparisons between attributes of R and attributes of S

<https://www.cs.rpi.edu/academics/courses/fall24/csci4380/fall2024/course_notes/relational_algebra.html>

### Operators

**% - Like** `.*` **in regex**

- This could be like `%EGG` will find `(.*)EGG`
- This could also be like `EGG%` will find `EGG(.*)`

**<> - NEQ**

- WHY IN THE EVER-LOVING **FUCK** IS THIS THE NEQ OPERATOR

**join\_{attr=attr1}**

- natural join with one column
- takes one col and maps it to the other
- does not copy things without matching values

**Example:**

`set1 join_{attr_in_set_1=attr_in_set_2} set2`

**Example:**

```
R(Num)
find the largest Num in R
the largest Num in R is the only Num which is not smaller than another Num2 in R
to find the Nums which are smaller than another Num2 we join R to a copy of itself
R2(Num2) = R
Join = R join{Num<Num2} R2
R - project{Num}Join
```

![image (5).png](.attachments.34361/image%20%285%29.png)

### Normalization Theory

### functional dependencies

<https://www.geeksforgeeks.org/what-is-functional-dependency-in-dbms/>

A dependency function (FD) is a database constraint that determines the relationship of one attribute to another in a [database management system (DBMS)](https://www.geeksforgeeks.org/introduction-of-dbms-database-management-system-set-1/).  Functional dependencies help maintain the quality of data in the database. Functional dependence is a relationship that exists between two attributes. It usually exists between the primary key and non-prime attributes in the table.

**Example:** **X -> Y**

In this case, the left side of the arrow is the determinant and the right of the arrow is dependent. X will be the primary attribute and Y will be a non-prime attribute of the table. It shows that column X's attributes uniquely identify column Y's attributes to satisfy this functional dependency.

***AKA each value on the left side of the arrow is associated with exactly one thing on the right side of the arrow***

#### Functional Dependency Keys

A set of keys that implies all other dependencies

**Example:**

You are given the following set F2 of functional dependencies for relation R(A,B,C,D,E,F):  
F2 = {AB -> CD, D->E, CA->B}

The keys would be ABF and ACF

### **Inference Rules**

FDs stands for Functional Dependencies. These are the set of attributes, which are logically related to each other.

**There are 6 inference rules:**

- **Reflexive Rule:**  if B is a subset of A then A logically determines B. Formally, **B ⊆ A** then **A → B**. 
  - Example: Let us take an example of the Address (A)  of a house, which contains so many parameters like House no, Street no,  City, etc. These all are the subsets of A. Thus, address (A) → House no.  (B).
- **Augmentation Rule:** It is also known as [**Partial dependency**](https://www.geeksforgeeks.org/differentiate-between-partial-dependency-and-fully-functional-dependency/).  If A logically determines B, then adding any extra attribute doesn’t change the basic functional dependency. 
  - Example: **A → B**, then adding any extra attribute let's say C will give **AC → BC** and doesn’t make any change.
- **Transitive rule:** if A determines B and B determines C, then it can be said that A indirectly determines C. 
  - Example: If **A → B** and **B → C** then **A → C**.
- **Union Rule:** If A determines B and C, then A determines BC. 
  - Example: If **A → B** and **A → C** then **A → BC.**
- **Decomposition Rule:** It is perfectly the reverse of the above Union rule. If A  determined BC then it can be decomposed as A → B and A → C. 
  - Example: If **A → BC** then **A → B** and **A → C.**
- **Pseudo Transitive Rule:** If A determines B and BC determines D then BC determines D. 
  - Example: If **A → B** and **BC → D** then **AC → D**.

### Prime Attribute

Given a relation R and a set F of fds, X is a superkey if X+ is all attributes in R (in other words: X->X+ is in F+).

### Basis

A set of functional dependencies forms a basis, if there is only one attribute on the right-hand side of each functional dependency

### Minimal Basis:

A set of functional dependencies F if we can not remove any fd or any attributes without changing the meaning (closure)

##### Algorithm for Converting a set F to a minimal basis

1. convert F to a basis form by using the splitting rule
2. Remove all trivial dependencies
3. Suppose X --> Y is in F, create F' by removing X --> Y
   1. If X+ is the same in F and F' then C --> Y can be removed
   2. AKA if we attempt to remove the functional dependency and the closure is the same, then the FD was not important, as it can just be reconstructed from the inverse (Y->X)

```


COPY THIS EXAMPLE LATER (jesus christ)
```

### BOYCE-CODD NORMAL FORM (BCNF)

Given a relation R and a set of fds F, R is in BCNF iff for all fds in F of the form X -> Y one of the following is true:

1. X is a superkey of R, or
2. X -> Y is trivial.
3. Y is prime attribute

If a relational is in BCNF, then it is also in 3NF

NOTE\*: To formally find all keys, you must go through all subsets. Remember to get rid of superkeys once you find a minimal key

For example:

```
given 2 keys: AB, BC
which give you
AB+ = (A, B, C, D)
BC+ = (A, B, C, D)

the keys would be
AB+ = (A, B, C, D)
BC+ = (A, B, C, D)
BD+ = (B, D)

Superkeys: AB, ABC, ABD, ABCD, BC, BCD
Prime Attributes: A, B, C

BCNF:
AB --> C (OK because AB is a superkey)
AB --> D (OK because AB is a superkey)
C --> A (NOT OK becauseC is not a superkey and C --> A is not trivial)

3NF:
AB --> C (OK because AB is a superkey)
AB --> D (OK because AB is a superkey)
C --> A (OK ONLY IN 3NF NOT DCNF because A is a prime attr)
A --> A (OK because trivial)
ABD --> C (OK because ABD is a superkey)

is in 3NF
```

Prime attributes: appear in all keys

### Equivalency:

Two sets of functional dependencies F1 and F2 over the same relation R are equivalent if:

F1 = { A->C }

F2 = { A -> C, A -> A }

F1+ = F2+

These are equivalent because ignoring trivial dependencies (A -> A) they are the same

#### Decomposition

A decomposition of R into R1, R2, ...., Rn is valid if R, R2, etc make up all of the attributes of R and is given by

R1 = project\_{attributes of R1} (R)

R2 = project\_{attributes of R2} (R)

. . . .

Rn = project\_{attributes of Rn} (R)

a good decomposition is:

- lossless required property, all decompositions should be lossless 
  - a decomp is lossless IF AND ONLY IF we are guaranteed that for every possible instance of R that R < R1 \* R2 .... Rn
- dependency preserving (desired property)

### Multi-valued dependency

Represented by "->>". Means that the value on the right-hand side can be multiple values.

A multi-valued dependency of the form A1 ... AN ->> B1 ... Bm means that for all pairs of tuples t1 and t2 that agree on A (everything on the left), we can find a tuple v in R such that:

- v agrees with t1 and t2 on A's
- v agrees with t1 on B's
- v agrees with t2 on the remaining attributes (not A's or B's)

Ex in class:

rin ->> hobby

rin ->> phone_number

For a given rin, there can be multiple values for a hobby and/or phone_number.

#### Inference rules for MVDs

![image (6).png](.attachments.34361/image%20%286%29.png)

Every FD is a MVD. Every MVD is not necessarily an FD. This rule is called FD promotion.

Complementation rule: If A1 ... AN =>> B1 ... Bm is true and C1 ... Ck are all attributres in R that are not As or Bs then A1 ... An =>> C1 ... Ck is also true.

#### 4NF:

A relation is in fourth normal form iff whenever A1... An =>> B1 ... Bm is a non-trivial MVD, then A1...An is a superkey. The notions of keys and superkeys depend on f.d.s only; adding MVDs does not change the definition of "key". To decompose a relation into fourth normal form, use an algorithm similar to BCNF decomposition algorithm using MVDs. Relations in 4NF C\_ Relations in BNCF C\_ Relations in 3NF.

# COPY EXAMPLE HERE

### Hw 1 notes from kuzmin:

min-max functions do not exist

cannot sort, select the best thing to use?

RelaX: <https://dbis-uibk.github.io/relax/calc/local/uibk/local/0> (recommended tool for checking your answer)

![NEED TO FIX THIS IMAGE IM WRONG](.attachments.34361/image%20%283%29.png)

![image (4).png](.attachments.34361/image%20%284%29.png)

## Normalization

Database structure such that any table can NOT express redundant info (no 2 birthdays per customer for example)

#### Normal Forms

Sets of data safety assessments/safety guarantees

###### **First Normal Form**

**Violating FNF**

- if you're using row order to convey information because row order is not maintained in a database
- mixing data types
- repeating groups 
  - re-adding data to each row
  - like an inventory where you add items again and again to each table like \[shield, shield, shield\]

__Rules__

1. Using row order to convey information is not permitted
2. mixing data types within the same column is not permitted
3. having a table without a primary key is not permitted
4. repeating groups are not permitted

**Solution**:

1. Add primary key
2. structure the table to avoid redundancies
   1. keep the count of every item in a player inventory instead of storing duplicates

###### Second Normal Form

**Definition: each non-key attribute must depend on the ENTIRE primary key**

deletion anomaly: deleting unrelated data breaks the logic

update anomaly: changing unrelated data breaks the logic

update insertion: having no data breaks the logic

###### Third Normal Form

Definition:

1. No non-key attribute may NEVER depend on a non-key attribute
2. Put another way, every non-key attribute in the table should depend on the key, the whole key, and nothing but the key (lmao)

Transitive Dependency: An attribute is dependent on an attribute that is dependent on another attribute

###### Fourth Normal Form

Definition: The only multivalued dependencies in a table MUST be dependencies on the key

Multi-value dependency:

- expressed using double arrow
- 

## Entity-Relationship (ER) Models

- Method for designing databases
- Helps give high-level view of the whole database, while normalization is more geared toward optimizing individual relations
- Help modularize database design
- ER models are object-oriented, not relational

#### ER Data Models

- ER Data models design a whole database using entities and relationships
- **ER Data models design a whole database using entities and relationships**
- Converting ER diagrams to a relational model: 
  - 1\. Convert each entity into a new relation R. Map entity keys for relation R. Map all other attributes to attributes of relation R.
  - 2\. Convert relationships based on cardinality 
    - One-to-one/one-to-many: Map the entity E1 that has one of the other entity E2 by adding E2's key as an attribute.
    - Many-to-many: Create a new relation R: Include in R the keys of all joining entities. The keys must include the keys of all entities that have an N participation.
  - Lossy decomposition: representing ternary relationship in three binary relationships does not give the same exact result
- foundational approach for database design
- focus on representing entities, their attributes, and the relationships between them
- ensure a clear and modular database structure
- play an important role in providing a high-level perspective before the database is normalized or transformed into a relational model.
- **Purpose**: ER models are used for designing databases and offer a high-level, object-oriented view of the data structure.
- **Normalization vs ER Models**: While normalization focuses on optimizing individual relationships, ER models help simplify the database by modularizing it into entities.
- **Modularization**: Entities represent major components, and relationships link these entities to one another.
- **Commonality**: ER modeling is widely used but is not the only database design method.

**Key Points**:

- Focus on entities and relationships.
- Modular design helps make normalization easier.

---

### **ER Data Models**

- **Entities and Relationships**: The core of ER modeling is to define entities (objects or classes) and relationships (connections) between them.
- **Relational Model Mapping**: Once the ER model is complete, it can be mapped to a relational data model. For example, after defining entities such as "Student" and "Faculty," they can be converted to relational tables.

---

### **Entity Classes and Attributes**

- **Entities**: An entity represents a class of objects, and each entity has attributes that describe its characteristics. 
  - **Attributes**: Should be simple values (no sets or multi-valued attributes).
  - **Key Attributes**: An entity must have a key attribute (or a combination of attributes) to ensure uniqueness.

**Example**:

- **Faculty**: `{id, name}`
  - The key is `id`.
- **Students**: `{id, name}`
  - The key is `id`.

**Notation**:

- Entities are represented with boxes, attributes with ellipses, and key attributes are underlined.

---

### **Relationships**

- **Linking Entities**: Relationships connect entities to one another. They represent how entities interact, such as "Students take Classes" or "Faculty work in Departments."
- **Participation Constraints**: These specify how many instances of an entity participate in the relationship. Participation can be one-to-one, one-to-many, or many-to-many.

**Example**:

- One-to-many relationship: Each department has many faculty members.
- Many-to-many relationship: Students can take multiple classes, and each class can have many students.

### **Keys in Relationships**:

- Relationships do not generally have keys, although some conventions might allow it.

---

### **Recursive Relationships**

- Sometimes, an entity can be linked to itself through a relationship. 
  - **Example**: A faculty can mentor other faculty members, establishing a "mentor-mentee" relationship within the same entity.

![image (13).png](.attachments.34361/image%20%2813%29.png)

---

### **Relationship Attributes**

- Relationships can have attributes, but these attributes should pertain to the relationship itself, not the connected entities. 
  - **Example**: A "grade" could be an attribute of the relationship between a student and a class they are enrolled in.

![image (14).png](.attachments.34361/image%20%2814%29.png)

---

### **Key Considerations in ER Models**

#### Referential Integrity

- Arrows represent the constraint that there is at most one entity of a type in the relationship. 
  - **Example**: Each department has exactly one chair, and a department cannot exist without a chair.

![image (15).png](.attachments.34361/image%20%2815%29.png)

#### Ternary Relationships

- Involves three entities but should be used carefully. Many ternary relationships can be decomposed into binary relationships. 
  - **Example**: A faculty advising multiple students on different majors might seem ternary, but binary relationships between faculty and students or faculty and majors may suffice.

![image (16).png](.attachments.34361/image%20%2816%29.png)

---

### **Weak Entities**

- A weak entity is dependent on a strong entity and cannot be uniquely identified without it. 
  - **Example**: Dependents of employees. The dependent name is unique only in the context of the employee.
- The key for a weak entity is not guaranteed to be unique in the database
- Think of the weak entity as a special subclass of some other entities

---

### **Design Rules**

- **Entity Must Have a Key**: Each entity must have a unique key that defines its identity.
- **Avoid Redundancy**: Do not repeat data unnecessarily; make separate entities when needed.
- **Minimize Complexity**: Avoid ternary or higher relationships if binary ones suffice.

---

### **Converting ER to Relational Model**

1. **Entities**: Mapped to tables, with their attributes becoming columns.
2. **Relationships**:
   - One-to-many relationships map the foreign key of the "many" side into the table of the "one" side.
   - Many-to-many relationships are ALWAYS represented by an additional table.
3. **Weak Entities**: Combined with supporting strong entities into a single table.

**Example**:

- **Employees**: `{Id, firstname, lastname, ...}`
- **Departments**: `{DeptId, DeptName, ...}`
- **Employee-Department Relationship**: Employees work in one department (one-to-many relationship)

---

### **Types of Relationships**

#### One-to-Many

- Represented with arrows from one entity to another. 
  - **Example**: Faculty to Department (each faculty belongs to one department, but each department can have many faculty)

![image (7).png](.attachments.34361/image%20%287%29.png)

![image (8).png](.attachments.34361/image%20%288%29.png)

#### One-to-One

- Both sides of the relationship have a "one" constraint. 
  - **Example**: Each department has one chair, and each faculty can be chair of one department.

![image (9).png](.attachments.34361/image%20%289%29.png)

![image (10).png](.attachments.34361/image%20%2810%29.png)

#### Many-to-Many

- The most common type of relationship, where multiple instances of both entities can interact. 
  - **Example**: Students and Classes (students enroll in many classes, and classes have many students).

![image (11).png](.attachments.34361/image%20%2811%29.png)

![image (12).png](.attachments.34361/image%20%2812%29.png)

---

## **Subclasses**

### **Subclasses in ER Models**

The **subclasses** section in Entity-Relationship (ER) models discusses how entities that share common attributes can be structured in a hierarchical manner. Subclasses are used when there is a need to represent entities that are specialized versions of a more general entity class, allowing inheritance of attributes and keys.

---

### **Key Concepts in Subclasses**

#### **Generalization and Specialization**

- **Generalization**: When multiple entities share common attributes, they can be generalized into a parent (superclass) entity. The individual entities (subclasses) inherit the attributes and key of the superclass.
- **Specialization**: Subclasses represent specialized entities that have additional attributes not shared with other subclasses or the parent.

#### **Type Hierarchy**

- In the subclass hierarchy, entities are organized in a **type hierarchy**, where each subclass inherits attributes from the parent entity class. 
  - The key and attributes of the parent entity (superclass) are passed down to the subclasses.

---

### **Example of Subclass Structure**

- **Superclass**: `People`
  - Attributes: `person_id, name`
- **Subclasses**: 
  1. **Students** (inherits from `People`) 
     - Attributes: `person_id, name, class`
  2. **Staff** (inherits from `People`) 
     - Attributes: `person_id, name, salary`

In this example, both `Students` and `Staff` inherit the `person_id` and `name` attributes from the `People` entity, but they also have their own specific attributes such as `class` (for students) and `salary` (for staff).

---

### **Disjoint and Overlapping Subclasses**

#### **Disjoint Subclasses**

- **Disjoint** subclasses mean that an entity can belong to only one subclass at a time. 
  - **Example**: A person can either be a student or a staff member, but not both.

#### **Overlapping Subclasses**

- **Overlapping** subclasses mean that an entity can belong to multiple subclasses at once. 
  - **Example**: A person could be both a student and a staff member, such as a teaching assistant who is also enrolled in classes.

---

### **Covering and Partial Subclasses**

#### **Covering Subclasses**

- In **covering** subclasses, all instances of the superclass must belong to at least one subclass. 
  - **Example**: All people in the `People` entity must either be a student or staff. No person can exist that is not part of one of these two subclasses.

#### **Partial Subclasses**

- In **partial** subclasses, some instances of the superclass may not belong to any subclass. 
  - **Example**: There could be people in the `People` entity who are neither students nor staff, representing individuals outside the scope of these two subclasses.

---

### **Mapping Subclasses to a Relational Model**

There are three basic ways to map a subclass hierarchy to a relational model:

#### **1. Storing Only Unique Information in Each Relation**

- In this method, only the attributes unique to each subclass are stored in the subclass tables, while the common attributes are stored in the superclass table.

**Example**:

```sql
People(person_id, name)  -- Superclass
Students(person_id, class)  -- Subclass
Staff(person_id, salary)  -- Subclass
```

- **Advantages**: Easy to find all people (common superclass table).
- **Disadvantages**: Joins are required to retrieve full information about a student or staff, leading to slower queries.

#### **2. Map Each Entity to a Separate Relation**

- Each subclass and the superclass are stored in separate tables, with repeated attributes included in each table.

**Example**:

```sql
People(person_id, name)  -- Superclass
Students(person_id, name, class)  -- Subclass
Staff(person_id, name, salary)  -- Subclass
```

- **Advantages**: Faster queries when retrieving information about a specific subclass.
- **Disadvantages**: Requires unions when querying for all people, as the data is spread across multiple tables.

#### **3. Combine All Information in a Single Relation**

- All data, including subclass-specific attributes, are stored in a single table, with some columns left `NULL` when they don't apply to an instance.

**Example**:

```sql
People(person_id, name, class, salary, is_student, is_staff)
```

- **Advantages**: Simplified data model, fast queries.
- **Disadvantages**: There may be many null values (e.g., `class` for staff members or `salary` for students), and the model may become harder to manage and query.

---

### **Choosing a Mapping Strategy**

The choice of mapping strategy depends on factors like the class hierarchy's **disjoint** or **overlapping** nature, and whether it is **covering** or **partial**. For example:

- If the subclasses are disjoint and covering, storing all the information in a single table may be efficient.
- If the subclasses are overlapping and partial, mapping each subclass to a separate table might be the better option.

---

### **Summary of Subclasses in ER Models**

- Subclasses allow for more detailed data modeling when entities share common attributes but also have their own specialized characteristics.
- The decision on how to map subclasses to a relational model should consider factors like performance, query complexity, and data integrity.

This structure helps ensure that the database accurately models real-world entities and relationships while optimizing for performance and maintainability.

---

# SQL

- SQL is an industry standard language for relational databases.
- Almost all database management systems implement SQL the same, except:
  - Core of the SQL standard is the same across all databases
  - Advanced features may vary from database to database
  - It is highly advisable to write queries that are portable from system to system: no bells and whistles unless it really gets you some strong performance gains.
- We will try to distinguish between core and special features as much as possible.
- A logical/declarative query language
- Express what you want, not how to get it
- Each SQL expression can be translated to multiple equivalent relational algebra expressions
- SQL is tuple based, each statement refers to individual tuples in relations
- SQL has bag semantics
- Recall RDBMS implementations of relations as tables do not require tables to always have a key, hence allowing the possibility of duplicate tuples.

  Same is true for SQL, an SQL expression may return duplicate tuples, unless they are removed explicitly.
- SQL is case insensitive (though strings are case sensitive of course)
- Syntax:
  - All statements must end with a semi-colon!
  - Strings are single-quoted.

### Components

- Query language:

  ```
  SELECT ... FROM ... WHERE ...
  ```

  allows you to write queries to find what is stored in databases.
- DML: data manipulation language

  ```
  INSERT
  UPDATE
  DELETE
  ```

  allows you to change the contents of the existing tables
- DDL: data definition language

  ```
  CREATE DATABASE
  CREATE TABLE
  ALTER TABLE
  DROP TABLE
  ```

  allows you to define database objects: schema, tables, indices, etc.

### Control Flow

1. From: read relations involved in the form
2. Where: check for each tuple if it passes the where clause
3. Select:
   1. for tuples that pass the where clause
   2. construct the output by the projection of attributes in select

## Syntax

#### General

```SQL
SELECT
   baker
FROM
   bakers
WHERE
   hometown = 'London'
   and age < 30;
```

this is equivalent to

`project_{ baker}(select_{ hometown == 'London' and age < 30 }(Bakers))`

This will have duplicates however, so we use...

#### Duplicate Removal

```SQL
SELECT DISTINCT
   baker
FROM
   bakers
WHERE
   hometown = 'London'
   and age < 30;
```

#### SELECT

- You can rename attributes returned
- You can use expressions over the attributes
- You can return constants
- Optionally, you can remove duplicates using distinct (only one DISTINCT clause in a single query)

```SQL
SELECT
      LEFT(fullname, strpos(fullname, ' ')) as firstname,
      UPPER(substring(fullname from strpos(fullname, ' ')+1)) as lastname,
      'baker' as position,
      occupation || ' from: ' || hometown as label
  FROM
      bakers ;

-- position is a new column with a fixed value, constant 'baker'
-- firstname is a substring of a column
-- label is a concatenation of two strings
-- functions can be combined in complex expressions
```

#### WHERE

- WHERE statement is equivalent to the selection in relational algebra.
- It contains a Boolean expression over individual tuples
- For each tuple produced by the FROM statement, we check whether the WHERE statement is true.

#### FROM

running `SELECT * FROM bakers, technicals ;` will create a **cartesian product** from the two tables

if we want to do a **join** we MUST include a join condition

```
SELECT *
FROM bakers b, technicals t
WHERE b.baker = t.baker;
```

- The variables b and t are aliases for the table names, especially needed if the two tables have attributes with the same name
- `SELECT attributes FROM R1,R2,.., Rn WHERE Conditions` is equivalent to

  ![image (18).png](.attachments.34361/image%20%2818%29.png)

### Regular Expressions using LIKE

You can compare a string using regular expressions, but you **must** `LIKE` (not `=`)

- % stands for 0 or more characters
- \_ stands for exactly 1 character

```SQL
days LIKE '%R%'
days LIKE '_R'
days = 'R'
days = '%R%'
```

*Note: you can change the escape char using the* `ESCAPE` *keyword*

```SQL
like '%x%bc' ESCAPE 'x'
// is the same as
like '%\%bc'
```

#### Special Characters

- Strings are delimited by single quote
  - **__Escape single quote by repeating it__**:

    ```
    SELECT
        'professor''s cat' ;
    ```
- Any special character needs to be escaped. The general escape character is `\`.

  ```
  select name || E'\n' || email from students ;
  ```

  Returns values that has a newline in them.

#### NULL

- any comparison involving a NULL value returns UNKNOWN
- WHERE statement will only return tuples that evaluate to True. Any tuples with UNKNOWN values are eliminated.
- Boolean conditions with UNKNOWN statements need to be evaluated first

```SQL
NULL = 5   -- evaluates to UKNOWN
NULL > 5   -- evaluates to UKNOWN
NULL LIKE '%' -- evaluates to UKNOWN

NULL = 5 OR   4>5    -- EVALUATES TO UNKNOWN
NULL = 5 AND  4>5    -- EVALUATES TO FALSE
```

- To check a value is NULL or not, no selection criteria will work. 
  - you MUST use the `IS NULL` or `IS NOT NULL` keywords

```SQL
select * from abc where val is NULL ; -- returns 1 tuple
select * from abc where val is NULL or val like '%'; -- returns all tuples
```

#### Complex expressions

- SQL has many functions for different data types
- Any expression involving these functions are allowed
- Some example functions: 
  - String operations: `||, upper, lower, position, substring, trim`
  - Numerical operations: `+,-,*,/,%,^,!`
  - Mathematical operations: `abs, ceil, floor, log, mod, round, sqrt`
  - Utilities: `random, now`

### Date-based data types

Data types:

- Date (year, month, day)
- Time of day
- Timestamp (date and time combined)
- Interval (a time duration)

complex example:

```SQL
date '2016-01-28' + 2 = date '2016-01-30'   --default assumption of day
date '2016-01-28' + interval '2 day' = timestap '2016-01-30 00:00:00'
date '2016-01-28' + interval '3 hours' = timestamp '2016-01-28 03:00:00'
timestamp '2016-01-28 03:00:00' + interval '10 hours' = timestamp '2016-01-28 13:00:00'
time '12:00:00' + interval '8 hours' = time '20:00:00'
date '2016-05-19' - date '2016-01-28' = 112   -- integer number of days
```

*Note: Postgresql functions allow complex operations over date/time*

```SQL
extract(field from timestamp)  --day, month, year, hour,
                               --minute, seconds, dow
select extract(year from now());
date_part
-----------
2016
(1 row)
```

#### **Examples:**

```SQL
-- Convert between data types:
to_char(timestamp, text)
to_date(text, text)
to_date('02 29 2016', 'MM DD YYYY')

-- check whether two time intervals overlap with each other
select (date '2016-03-01', date '2016-03-31') overlaps
       (date '2016-02-25', date '2016-03-04');
-- returns True

select (date '2016-03-01', date '2016-03-31') overlaps
(date '2016-02-25', date '2016-02-29');
-- returns False

-- Find requirements that have been enforced for at least 1 year
select * from requires where cast(now() as date) - enforcedsince > 365;

course_id | prereq_id | isenforced | enforcedsince
-----------+-----------+------------+---------------
         5 |         1 | t          | 2011-01-01
```

#### Set and Bag Operations

**SET operations**

- UNION
- INTERSECT
- EXCEPT

**BAG operations**

- UNION ALL
- INTERSECT ALL
- EXCEPT ALL

```SQL
(SELECT ... FROM ... WHERE ...)
UNION
(SELECT ... FROM ... WHERE ...)
```

*Note: Same as in relational algebra, the queries should be union-compatible*

**EXAMPLE**

Table `a1` with id values:  `1,2,2,2,3,3` Table `a2` with id values:  `2,3,3`

```sql
-- set operation, returns 1,2,3
select * from a1 union select * from a2 ;

-- returns 2,3
select * from a1 intersect select * from a2 ;

-- returns 1
select * from a1 except select * from a2 ;

-- returns 1,2,2,2,2,3,3,3,3  -bag union
select * from a1 union all select * from a2 ;

-- returns 2,3,3  -bag intersection
select * from a1 intersect all select * from a2 ;
```

**EXAMPLE 2**

```SQL
-- Return full name of all bakers who star baker but never won a technical challenge
SELECT b.fullname
FROM bakers b, results r
WHERE b.baker = r.baker and r.result = 'star baker'
EXCEPT
SELECT b.fullname
FROM bakers b, technicals t
WHERE b.baker = t.baker and t.rank = 1;
```

### AGGREGATES

Similar to the aggregates in bag relational algebra, you can find the aggregate for a specific column or combination of columns

- Commonly used aggregates are: `min`, `max`, `avg`, `sum`, `count`, `stddev`
- An aggregate returns a single tuple (unless accompanied by other clauses like GROUP BY or FILTER)

```SQL
-- Find total number of times ‘Kim-Joy’ won star baker.
SELECT count(*) as num_wins
FROM results
WHERE baker = 'Kim-Joy';
```

**Note:**

- `count(*)` counts the total number of tuples.
- `count(attribute)` counts the total number of values for a given attribute, disregarding the NULL values.
- `count(DISTINCT attribute)` counts the total number of distinct values for a given attribute, disregarding the NULL values.

#### GROUP BY

Instead of computing the aggregates for the whole query, it is possible to compute it for a group.

- Group by multiple attributes by finding tuples that have the same values for the grouping attributes
- For each group, produce a single tuple containing grouping attributes and any agregates over the group.
- To return an attribute from a relation, you MUST include it in the grouping attributes.

**Example**

Find the total number of star baker wins for each baker. Return the full name and hometown of each baker.

```SQL
SELECT b.baker, b.fullname, count(*) as numwins
FROM bakers b, results r
WHERE b.baker = r.baker and r.result = 'star baker'
GROUP BY b.baker, b.fullname;
```

#### GROUP BY - HAVING

- Group by statement can be followed by an optional HAVING clause.
- You can write conditions to eliminate groups in the HAVING clause
- Aggregates over the groups.
- All other conditions should be put in the WHERE clause to reduce the size of the relation to be grouped

**Example**

Find all bakers who have used ‘chocolate’ or ‘ginger’ in the showstopper challenge at least two different episodes and won star baker at least twice. Return their fullname

```SQL
SELECT b.baker, b.fullname
FROM bakers b, showstoppers ss, results r
WHERE
   b.baker = ss.baker
   and b.baker = r.baker
   and r.result = 'star baker'
   and (lower(ss.make) like '%ginger%' or lower(ss.make) like '%chocolate%')
GROUP BY
   b.baker
HAVING
   count(DISTINCT ss.episodeid) >= 2
   and count(DISTINCT r.episodeid) >= 2;
```

#### 

#### ORDER BY

- You can order the tuples returned by the query with respect to one or more attributes.

```sql
-- Return the students, order with respect to year (descending) and name (ascending).
SELECT * FROM episodes
ORDER BY viewers7day desc, id asc;
```

#### LIMIT

- You can limit the number of tuples returned
- is the **last possible statement to add**
- makes the most sense when combined with an order by

```sql
-- Find the top 3 bakers in terms of number of wins. Return their name
SELECT b.baker, b.fullname, count(*) as numwins
FROM bakers b , results r
WHERE
   b.baker = r.baker
   and r.result = 'star baker'
GROUP BY b.baker
ORDER BY numwins desc;
LIMIT 3;
```

---

# Lecture Notes: Advanced SQL Query Techniques

#### Generated by ChatGPT 4-o from my insane rambling notes because I'm sick and can't be fucked

---

## Introduction

In this lecture, we'll explore advanced SQL query techniques using a practical example involving a database schema and specific querying requirements. We'll cover topics such as regular expressions in SQL, data type conversions, handling `NULL` values, debugging SQL queries, and ensuring compatibility across different SQL dialects.

---

## Comprehensive SQL Concepts and Definitions for Future Assignments

---

## Table of Contents

 1. Understanding the Database Schema
 2. Basic SQL Statements
 3. Data Filtering Techniques
 4. Joining Tables
 5. Working with NULL Values
 6. Data Type Conversions and Casting
 7. Functions and Expressions
 8. Regular Expressions in SQL
 9. Extracting Numbers from Strings
10. Aggregate Functions and Grouping Data
11. Subqueries and Common Table Expressions (CTEs)
12. Sorting and Limiting Results
13. SQL Dialects and Compatibility
14. Error Handling and Debugging
15. Best Practices
16. Security Considerations
17. Conclusion
18. Appendices
    - Execution Order of SQL Statements
    - Common SQL Functions
    - Additional Resources

---

## 1. Understanding the Database Schema

Before writing SQL queries, it's crucial to understand the database schema:

- **Tables**: Structures that store data in rows and columns.
- **Columns**: Attributes or fields in a table.
- **Relationships**: How tables are related (e.g., primary keys, foreign keys).

### Example Schema:

- **bakers**: Stores baker information. 
  - Columns: `baker`, `fullname`, `age`, `occupation`, `hometown`.
- **episodes**: Contains episode details. 
  - Columns: `id`, `title`, `firstaired`, `viewers7day`, `signature`, `technical`, `showstopper`.
- **signatures**, **showstoppers**, **technicals**, **results**: Store challenge-specific data.

---

## 2. Basic SQL Statements

- `SELECT`: Retrieves data from a database. 
  - *Syntax*: `SELECT column1, column2 FROM table_name;`
- `FROM`: Specifies the table to query.
- `WHERE`: Filters records based on conditions. 
  - *Syntax*: `WHERE condition;`
- `ORDER BY`: Sorts the result set. 
  - *Syntax*: `ORDER BY column1 ASC|DESC;`

---

## 3. Data Filtering Techniques

### Pattern Matching:

- `LIKE`: Case-sensitive pattern matching. 
  - *Syntax*: `WHERE column LIKE 'pattern%';`
- `ILIKE`: Case-insensitive pattern matching (PostgreSQL). 
  - *Syntax*: `WHERE column ILIKE 'pattern%';`

### Using Wildcards:

- `%`: Represents zero or more characters.
- `_`: Represents a single character.

### Comparison Operators:

- `=`, `!=`, `>`, `<`, `>=`, `<=`

### Range and List Checks:

- `BETWEEN`: Checks if a value is within a range. 
  - *Syntax*: `WHERE column BETWEEN value1 AND value2;`
- `IN`: Checks if a value matches any value in a list. 
  - *Syntax*: `WHERE column IN (value1, value2, ...);`

---

## 4. Joining Tables

- `JOIN`: Combines rows from two or more tables based on related columns.

### Types of Joins:

- `INNER JOIN`: Returns records with matching values in both tables. 
  - *Syntax*: `FROM table1 INNER JOIN table2 ON table1.column = table2.column;`
- `LEFT JOIN`: Returns all records from the left table and matched records from the right table.
- `RIGHT JOIN`: Returns all records from the right table and matched records from the left table.
- `FULL OUTER JOIN`: Returns all records when there is a match in either table.

### Self-Join:

- A table joined with itself.
- Useful for comparing rows within the same table.
- Requires table aliases.
- *Syntax*: `FROM table_name t1 JOIN table_name t2 ON t1.column = t2.column;`

---

## 5. Working with NULL Values

- `NULL` represents missing or unknown data.
- `IS NULL` and `IS NOT NULL`: Check for NULL values.

### Handling NULLs:

- `COALESCE()`: Returns the first non-NULL value in a list. 
  - *Syntax*: `COALESCE(value1, value2, ...)`

### Example:

```sql
SELECT COALESCE(middle_name, 'N/A') AS middle_name FROM persons;
```

---

## 6. Data Type Conversions and Casting

- Ensures data types are compatible for operations.

### Casting:

- `CAST()`: Converts a value to a specified data type. 
  - *Syntax*: `CAST(expression AS data_type)`
- `::` Operator (PostgreSQL): Alternative casting syntax. 
  - *Syntax*: `expression::data_type`

### Example:

```sql
SELECT CAST('123' AS integer) AS number;
SELECT '123'::integer AS number;
```

---

## 7. Functions and Expressions

### Mathematical Functions:

- `ABS()`: Absolute value.
- `ROUND()`: Rounds a number to a specified number of decimal places. 
  - *Syntax*: `ROUND(number, decimals)`
- `CEILING()`/`FLOOR()`: Rounds up or down to the nearest integer.

### String Functions:

- `UPPER()`/`LOWER()`: Converts string case.
- `TRIM()`: Removes whitespace.
- `SUBSTRING()`: Extracts a substring. 
  - *Syntax*: `SUBSTRING(string FROM pattern)`

### Date Functions:

- `CURRENT_DATE`, `CURRENT_TIMESTAMP`
- `DATEADD()`, `DATEDIFF()`

---

## 8. Regular Expressions in SQL

- Allows complex pattern matching.

### Syntax:

- **PostgreSQL**: 
  - `~`: Case-sensitive match.
  - `~*`: Case-insensitive match.
- **MySQL**: 
  - `REGEXP`: Pattern matching operator.

### Example:

```sql
-- Find rows where 'make' contains 'cake' as a whole word
SELECT * FROM showstoppers WHERE make ~* '\ycake\y';
```

### Regex Components:

- `^`: Start of string.
- `$`: End of string.
- `.`: Any single character.
- `*`: Zero or more occurrences.
- `+`: One or more occurrences.
- `[]`: Character class.
- `\d`: Digit.
- `\w`: Word character.
- `\s`: Whitespace.
- `\y`: Word boundary (PostgreSQL).

---

## 9. Extracting Numbers from Strings

- Useful for comparing numerical values embedded in text.

### Using `SUBSTRING()` and Regular Expressions:

```sql
-- Extract leading numbers from a string
SUBSTRING(column FROM '^\d+')
```

### Casting Extracted Strings:

```sql
-- Convert extracted numbers to integer
CAST(SUBSTRING(column FROM '^\d+') AS integer)
```

### Example:

```sql
SELECT
  CAST(SUBSTRING(signature FROM '^\d+') AS integer) AS signature_number
FROM episodes;
```

---

## 10. Aggregate Functions and Grouping Data

### Aggregate Functions:

- `COUNT()`: Number of rows.
- `SUM()`: Total sum.
- `AVG()`: Average value.
- `MIN()`/`MAX()`: Minimum or maximum value.

### Grouping Data:

- `GROUP BY`: Groups rows sharing values. 
  - *Syntax*: `GROUP BY column1, column2`
- `HAVING`: Filters groups based on aggregate conditions. 
  - *Syntax*: `HAVING condition`

### Conditional Aggregation:

- `COUNT(*) FILTER (WHERE condition)`: Counts rows meeting a condition.

### Example:

```sql
SELECT
  department,
  COUNT(*) AS total_employees,
  COUNT(*) FILTER (WHERE salary > 50000) AS high_earners
FROM employees
GROUP BY department;
```

---

## 11. Subqueries and Common Table Expressions (CTEs)

### Subqueries:

- Nested queries within a main query.
- *Syntax*: `SELECT ... FROM (SELECT ...) AS sub;`

### Common Table Expressions (CTEs):

- Temporary result set that can be referenced within the main query.
- *Syntax*:

```sql
WITH cte_name AS (
  SELECT ...
)
SELECT ...
FROM cte_name;
```

### Example:

```sql
WITH high_viewers AS (
  SELECT id, viewers7day FROM episodes WHERE viewers7day > 10
)
SELECT * FROM high_viewers;
```

---

## 12. Sorting and Limiting Results

### Ordering:

- `ORDER BY`: Sorts results. 
  - *Syntax*: `ORDER BY column1 ASC|DESC, column2;`

### Limiting:

- `LIMIT`: Limits the number of rows returned. 
  - *Syntax*: `LIMIT number;`
- `FETCH FIRST`: Alternative to LIMIT. 
  - *Syntax*: `FETCH FIRST number ROWS ONLY;`

### Example:

```sql
SELECT * FROM episodes ORDER BY viewers7day DESC LIMIT 5;
```

---

## 13. SQL Dialects and Compatibility

### Differences Across Databases:

- **PostgreSQL**: 
  - Uses `ILIKE` for case-insensitive LIKE.
  - Supports `~` and `~*` for regex.
  - Allows `::` casting.
- **MySQL**: 
  - Uses `REGEXP` for regex.
  - Does not support `ILIKE`; use `LOWER()` with `LIKE`.

### Ensuring Compatibility:

- **Check Documentation**: Refer to specific database manuals.
- **Avoid Proprietary Features**: Use standard SQL when possible.
- **Test Queries**: Validate in the target database environment.

---

## 14. Error Handling and Debugging

### Common Errors:

- **Syntax Errors**: Misspelled commands, missing commas.
- **Type Mismatch**: Incompatible data types.
- **Undefined Functions**: Using functions not available in the SQL dialect.

### Debugging Steps:

1. **Read Error Messages Carefully**: They often indicate the issue.
2. **Check Syntax**: Ensure correct command usage.
3. **Validate Data Types**: Use casting if necessary.
4. **Simplify the Query**: Break it down to identify the problematic part.
5. **Use Comments**: Comment out sections to isolate errors.

### Example Error and Resolution:

```sql
-- Error: function round(double precision, integer) does not exist
-- Solution: Cast the number to numeric
SELECT ROUND(viewers7day::numeric, 2) FROM episodes;
```

---

## 15. Best Practices

- **Use Aliases for Clarity**: 
  - Shorten table/column names.
  - *Example*: `SELECT e.name FROM employees AS e;`
- **Filter Early**: 
  - Apply `WHERE` clauses before `GROUP BY` or `JOIN` to reduce data size.
- **Optimize Joins**: 
  - Ensure proper indexing on join columns.
  - Use appropriate join types.
- **Handle NULLs Appropriately**: 
  - Be aware of NULL behavior in comparisons and functions.
- **Comment Your Code**: 
  - Use `--` for single-line and `/* ... */` for multi-line comments.
- **Consistent Formatting**: 
  - Write SQL keywords in uppercase.
  - Use indentation for readability.

---

## 16. Security Considerations

- **Prevent SQL Injection**: 
  - Use parameterized queries.
  - Avoid concatenating user input into SQL statements. signs\*\*

You can also return a table of rows:

> - Return each tuple with RETURN NEXT and finish with RETURN
> - As these return a table, they are called in the FROM clause. See the loop section below for examples.

### Handling SQL

````SQL
CREATE FUNCTION sales_tax(subtotal real) RETURNS boolean AS 
- **Limit Permissions**:
  - Grant only necessary privileges to users.
- **Validate Input**:
  - Sanitize user inputs.
  - Use input validation to enforce data integrity.

---

## 17. Conclusion

Understanding these SQL concepts equips you to handle various data querying and manipulation tasks effectively. By mastering pattern matching, data type conversions, error handling, and other advanced techniques, you can write efficient and robust SQL queries for future assignments.

---

## 18. Appendices

### Execution Order of SQL Statements

1. **FROM**: Data source specification.
2. **JOIN**: Combining tables.
3. **WHERE**: Row-level filtering.
4. **GROUP BY**: Grouping rows.
5. **HAVING**: Group-level filtering.
6. **SELECT**: Column selection.
7. **ORDER BY**: Sorting results.
8. **LIMIT**: Limiting output.

---

### Common SQL Functions

- **String Functions**: `CONCAT()`, `LENGTH()`, `REPLACE()`
- **Date Functions**: `NOW()`, `DATE_PART()`, `AGE()`
- **Numeric Functions**: `POWER()`, `MOD()`, `SQRT()`
- **Conversion Functions**: `TO_CHAR()`, `TO_DATE()`

---

### Additional Resources

- **PostgreSQL Documentation**: [postgresql.org/docs](https://www.postgresql.org/docs/)
- **MySQL Documentation**: [dev.mysql.com/doc](https://dev.mysql.com/doc/)
- **Regular Expressions Reference**: [regular-expressions.info](https://www.regular-expressions.info/)
- **SQL Tutorial**: [w3schools.com/sql](https://www.w3schools.com/sql/)

---

## Practice Examples

### Example 1: Using Regular Expressions

```sql
-- Find episodes where the signature starts with two digits and a space
SELECT id, title, signature
FROM episodes
WHERE signature ~ '^\d{2} .+';
````

### Example 2: Extracting Numbers and Comparing

```sql
-- Select episodes where the signature number is greater than the technical number
SELECT id, title
FROM episodes
WHERE
  CAST(SUBSTRING(signature FROM '^\d+') AS integer) >
  CAST(SUBSTRING(technical FROM '^\d+') AS integer);
```

### Example 3: Handling NULLs with COALESCE

```sql
-- Replace NULL hometowns with 'Unknown'
SELECT fullname, COALESCE(hometown, 'Unknown') AS hometown
FROM bakers;
```

### Example 4: Rounding and Division

```sql
-- Calculate normalized viewers and round to two decimal places
SELECT
  id,
  ROUND((viewers7day / 100)::numeric, 2) AS viewers_normalized
FROM episodes;
```

---

## Final SQL Query Example with Explanation

### Question

Return the maximum absolute difference in `viewers7day` value between two consecutive episodes. Name the returned attribute `maxviewerdiff`.

### SQL Query

```sql
SELECT MAX(ABS(e1.viewers7day - e2.viewers7day)) AS maxviewerdiff
FROM episodes e1
JOIN episodes e2 ON e1.id = e2.id - 1;
```

### Explanation

- **Objective**: Find the largest absolute difference in `viewers7day` between consecutive episodes.
- **Approach**: 
  - **Self-Join**: Join the `episodes` table to itself to compare consecutive episodes. 
    - `e1` represents the current episode.
    - `e2` represents the next episode.
  - **Join Condition**: `e1.id = e2.id - 1` ensures pairing of consecutive episodes.
  - **Calculate Difference**: `ABS(e1.viewers7day - e2.viewers7day)` computes the absolute difference in viewers.
  - **Aggregate Function**: `MAX()` retrieves the maximum difference.
- **Result**: The query returns a single value `maxviewerdiff`, representing the largest viewer drop or increase between two consecutive episodes.

---

## Closing Thoughts

By integrating these advanced topics into your SQL knowledge base, you enhance your ability to write complex queries, troubleshoot issues, and ensure your code is both efficient and secure. Practice regularly with different scenarios to solidify these concepts.

---

## Procedural Programming

To enable the use of SQL for costly queries, while making it possible to write code/procedures on top of it, databases support a number of options.

- Server-side
- Client-side

#### Server-side

- Languages make it possible to define procedures, functions, and triggers
- These programs are compiled and stored in the database server
- They can also be called by queries

#### Client-side

- Languages allow programs to integrate querying of the database with a procedural language
- Coding in a host language with db hooks (C, C++, Java, Python, etc.) using the data structures of these languages
- Coding in frameworks with their own data models (Java, Python, etc) with similar db hooks as in above.

### Programming in SQL

**All programming paradigms support:**

- methods to execute queries/update statements
- executing any SQL statement, catching the outcome, and interpreting the errors if any
- input values from variables into queries and outputting the values from queries into variables
- loop over query results (if multiple tuples)
- raise exceptions, which results in rollbacks of transactions
- store and reuse queries in the shape of cursors
- starting and committing transactions

**Client-side programs also support:**

- opening/closing connections
- allocating/releasing database resources for queries

**Server-side language examples (Generally database-specific):**

- pl/pgsql: a generic procedural language for postgresql
- pl/pyhton: a procedural language that is an extension of python

**Client-side language examples:**

- libpq: a C library for postgres which uses library calls specific to psql
- OCCI: Oracle library for C
- ECPG: embedded programming in SQL, based on the embedded programming standard with a postgresql specific pre-compiler, an the standard C compiler

**Frameworks**  
based on specific design principles for developing database backed applications  
examples:

- Object-relational-mapping used by Rails, Hibernate, Django, WebObjects, .NET (different frameworks have different models)
- Note that the frameworks can be built on top of other languages (such as Java + JDBC)

### pl/pgsql

- supports the same data types as the database
- programs and functions can be compiled and used directly by the db server
- main pl/pgsql block is in this form:

```pl/pgsql
[ <<label>> ]
[DECLARE
variable declarations ]
BEGIN
statement
END [ label ] ;
```

- Variable types

```PSQL
integer
numeric(5)
varchar
tablename%ROWTYPE
tablename.columname%TYPE
RECORD
-- ROWTYPE and RECORD have subfields, i.e. x.name.
```

#### Constructs

**Conditionals**

```SQL
IF ... THEN ... ELSIF ... THEN ... ELSE ... END IF
Loops:
[ <<label>> ]
LOOP
statements
END LOOP [ label ];
```

**Returning a value**

- pl/pgsql functions do not allow you to modify input variables
- RETURN will return a value. As a result, you can call it like a constant in the select statement shown below:

```postgresql
CREATE FUNCTION sales_tax(subtotal real, state varchar) RETURNS real AS $$
DECLARE
   adjusted_subtotal real ;
BEGIN
   IF state = 'NY' THEN
       adjusted_subtotal = subtotal * 0.08 ;
   ELSIF state = 'AL' THEN
       adjusted_subtotal = subtotal ;
   ELSE
       adjusted_subtotal = subtotal * 0.06;
   END IF ;
   RETURN adjusted_subtotal ;
END ;
$$ LANGUAGE plpgsql ;
```

we can test it like:

```SQL
select sales_tax(100, 'NY') ;

sales_tax
-----------
8
(1 row)
```

\*\*The whole body of the function is entered within the two dollar signs\*\*

You can also return a table of rows:

> - Return each tuple with RETURN NEXT and finish with RETURN
> - As these return a table, they are called in the FROM clause. See the loop section below for examples.

### Handling SQL

```SQL
CREATE FUNCTION sales_tax(subtotal real) RETURNS boolean AS $$
DECLARE
   adjusted_subtotal real ;
BEGIN
   adjusted_subtotal = subtotal * 0.06;
   BEGIN
       INSERT INTO temp VALUES (adjusted_subtotal) ;
       RETURN true ;
   EXCEPTION WHEN unique_violation THEN
       RETURN false ;
   END ;
END ;
$$ LANGUAGE plpgsql ;
```

when you run this function, a row is inserted into table temp

#### Executing queries

When the query returns a single row, then we can read it directly into a variable

```SQL
SELECT * INTO myrec FROM emp WHERE empname = myname;
  IF NOT FOUND THEN
  RAISE EXCEPTION 'employee % not found', myname;
  END IF;

-- input: myname, output: myrec
```

When the query returns multiple rows, then a loop is needed to go through them one by one.

- A query returns a stream of tuples, which needs to be processed.
- Equally important is closing the stream associated with a query if required by the programming language.

```SQL
[ <<label>> ]
FOR target IN query LOOP
statements
END LOOP [ label ];

DECLARE
myRow  RECORD ;
lastX      INT ;
yCnt       INT ;
BEGIN
   lastX = 0 ;
   yCnt = 0 ;
   FOR myRow IN
          SELECT x,y, count(*) as num
          FROM temp GROUP BY x,y ORDER BY x, num ASC LOOP
      yCnt = yCnt + 1;
      IF yCnt < 4 AND lastX = myRow.x THEN
          INSERT INTO temp2 VALUES(myRow.x, myRow.y, myRow.num) ;
      ELSIF lastX <> myRow.x THEN
          lastX = myRow.x ;
          yCnt = 1 ;
          INSERT INTO temp2 VALUES(myRow.x, myRow.y, myRow.num) ;
      END IF ;
   END LOOP ;
RETURN 1 ;
END ;
```

Example 2:

```SQL
CREATE TABLE names (name VARCHAR(255)) ;

CREATE FUNCTION allnames() RETURNS SETOF names AS $$
DECLARE
   row RECORD ;
BEGIN
   FOR row in SELECT DISTINCT crsname FROM courses LOOP
       RETURN NEXT row ;
   END LOOP ;
   RETURN ;
END ;
$$ LANGUAGE plpgsql ;
```

call it like `select * from allnames();`

### Cursors

- A query with a handle and can have input.
- Can be defined once and used many times to read tuples.
- A cursor is optimized once, reducing the cost of optimizing the query many times.
- Functions may return reference to a cursor, allowing a program to read tuples that are returned.
- Cursors provide a more efficient implementation of queries returning many tuples.
- First, declare cursors:

  ```SQL
  DECLARE curs2 CURSOR FOR SELECT * FROM tenk1;
  ```
- Then, execute the associated query by opening them:

  ```SQL
  OPEN curs2;
  ```
- Then, retrieve tuples in the result using fetch:

  ```SQL
  FETCH curs2 INTO foo, bar, baz;
  ```

or

> ```SQL
> FOR recordvar IN curs2 LOOP
> ```

- When finished, close the cursor to release allocated memory:

  ```SQL
  CLOSE curs2;
  ```
- Cursors can also be used for update/delete if it is pointing to a specific tuple (similar to the notion of an updatable view). - Update/delete the tuple the cursor is pointing to

### Exceptions

- When an SQL statement is executed, if it is not  successful, it raises an error. This error can be caught in the usual  try/catch format:

  ```SQL
  BEGIN
  statement
  EXCEPTION WHEN condition THEN
    statement
  END ;
  ```
- Exception conditions define integrity violations, statement errors, connection errors, etc.
- The pl/pgsql statements can also raise exceptions to be caught by the calling statement:

  ```SQL
  RAISE NOTICE  ''
  RAISE EXCEPTION ''
  ```
- Also uncaught exceptions within the function will be raised when the function fails.

### OCCI

[helpful link](https://indico.cern.ch/event/190324/sessions/129485/attachments/269827/377592/OCCI.pdf (preview))

calls an Oracle C-library but is designed to closely follow the JDBC for Java which is a standard

```Java
#include <occi.h>
using namespace oracle::occi;

Environment* const env = Environment::createEnvironment(Environment::DEFAULT);

Connection* const con = env->createConnection(user, pass, osid);

Statement* const s =
       con->createStatement("SELECT a.stageName"
                            " FROM movies.actors a"
                            " WHERE a.stagename like 'A%'");
```

terminate environment using `Environment::terminateEnvironment(env);` to release the memory

terminate the connection using `env->terminateConnection(con);`

A single connection can be used to query the same database multiple times in parallel or sequentially.

#### Querying

To execute a query, you will need to:

- Create an SQL statement and load it into a `statement` type object
- Execute your query which will return one or more tuples
- Create a `resultset` object that will allow you to iterate through the tuples returned by the query
- Close your resultset object so that the database and your program releases the necessary memory
- Close your statement if you will no longer use it. Remember that you can use a single statement object repeatedly with different SQL queries

#### Statements

```SQL
-- create a statement for a specific condition
Statement* sel_all_stmt
con->createStatement("SELECT attr1 FROM my_table");
-- ..statements to execute this query here..

-- Change the query for this statement if necessary
sel_all_stmt->setSQL("SELECT attr2, attr3 FROM new_table");

-- When finished, release the statement object
con->terminateStatement(sel_all_stmt);
```

#### Parametrized Statements

- can be executed multiple times with different values

example:

suppose a query that finds the name of a specific employee may be executed multiple times for different employees.

`Statement* sel_name con->createStatement("SELECT name FROM employee WHERE id = :1");`

that query will need to be supplied by one value before it is executed

`sel_name->setInt(1, 112223333);`

- The type used in the “set” method should set the type of the value being supplied.
- This type of query is UNPREPARED if the required value is not supplied by the program.
- A prepared statement is optimized once and the query plan is used multiple times for each execution of the query

EXAMPLE:

```SQL
Statement* sel_name con->createStatement("SELECT name FROM employee WHERE id = :1 AND Office = :2");
sel_name->setInt(1, 112223333);
sel_name->setString(2, “AE125”);
```

OR

```SQL
Statement* sel_name con->createStatement("SELECT name FROM employee WHERE id = :1 AND Office = :2");
sel_name->setInt(1, ssnVar);
sel_name->setString(2, officeVar);
```

#### Update statements

- All statements that change the database are executed using `executeUpdate` method.
- Examples: `insert, update, delete, create, drop`

EXAMPLE:

```SQL
stmt->executeUpdate(“CREATE TABLE basket_tab (fruit VARCHAR2(30), quantity NUMBER)”);

statement* s1 =
con->createStatement("INSERT INTO my_table (a, b) VALUES (1, 'A')");
s1->executeUpdate();
```

#### Select statements

- uses `executeQuery()` method
- To process these tuples, you need a result set object which processes tuples in a similar way to a file
- Need to open, iterate through, and close a result set to access the tuples
- this essentially returns an iterator (use `itr->next()` , returns false when done, etc)
- getXXX(i) means attribute i of the query should have type XXX

```SQL
statement* s1 = con->createStatement(
         "SELECT id, name FROM emp WHERE id < 1000");
ResultSet r = s1->executeQuery();
while (r->next()) {
    varId = r->getInt(1) ;
    varName = r->getString(2) ;
}
s->closeResultSet(r);
```

#### Errors and Statuses

```SQL
try{
   ... operations which throw SQLException ...
}
catch (SQLException e){
   cerr << e.what();
	 cerr << e.getMessage();
	 cerr << e.getErrorCode();
}
```

- it is possible to check the status of a statement during runtime, which can be \``` UNPREPARED, PREPARED, RESULT_SET_AVAILABLE, UPDATE_COUNT_AVAILABLE` ``
- you can check if the result set us \``END_OF_FETCH = 0`, `DATA_AVAILABLE`, or even `r->isNull`
- `vector<MetaData> getColumnListMetaData() const;` will return the number, types and properties of aResultSet’s columns

#### Transactions

```C
con->commit();
con->rollback();
```

After a rollback/commit, the next query/update will start a new transaction

EXAMPLE:

```Java
int counter = 1;
try
{
		Environment *env = Environment::createEnvironment(Environment::DEFAULT);
		Connection *conn = env->createConnection(user, pwd, db);

		Statement *stmt = conn.createStatement();
		statement->setAutoCommit(false);

		stmt->execute("INSERT INTO TestTable VALUES ('bla',123)");	
		conn->commit();
		conn->terminateStatement(stmt);
}
catch (oracle::occi::SQLException ex)
{
    connection->rollback();
    connection->terminateStatement(statement);
    throw DatabaseException(ex.what());
}
```

::: info
Autocommit is like calling `stmt->commit();` after every `stmt->execute()`

:::

### JDBC

- standard for any database product and a Java program for the same purpose
- JDBC and OCCI are very similar to each other and have almost identical set of classes and methods. In fact, OCCI is based on JDBC
- To accomplish the communication between a Java program and a database, a set of libraries called a “driver” is needed
- JDBC drivers are specific to the database server

EXAMPLE:

```Java
import java.sql.*;
import oracle.sql.*;
import oracle.jdbc.driver.*;
class Employee
{
public static void main (String args []) throws SQLException
{//Set your user name and the password
String userName = "dummy" ;
String passWord = "dummy" ;

// Load the Oracle JDBC driver
DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver());

   Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@acadoracle.server.rpi.edu:1521:ora9",userName,passWord);
// Create a statement which will return a cursor that
// will allow you to scroll the result set using both
// "next" and "previous" methods

try {
      Statement stmt = conn.createStatement
           (ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);

      ResultSet rset = stmt.executeQuery("SELECT name, oid FROM items ");

      // Iterate through the result and print the item names
      while (rset.next ()) {
          //Get item name, which is the first column
          System.out.println (rset.getString (1));

          PreparedStatement pstmt = conn.prepareStatement ("SELECT name FROM owners WHERE oid = ?") ;

          //Feed the owner id retrieved from rset into pstmt
          pstmt.setInt(1, rset.getInt (2));
          ResultSet dset = pstmt.executeQuery() ;
          if (dset.next())
              System.out.println(dset.getString (1));
      } }
 }
 catch (SQLException) { error-handling-code } }  }
```

### Python DB-API

- DB-API is a generic db interface for python (like JDBC)
- psycopg2 is a python adapter that implements DB-API0

```py
import psycopg2 as dbapi2

db = dbapi2.connect (database="python", user="python", password="python")
cur = db.cursor()

cur.execute ("SELECT * FROM versions");
rows = cur.fetchall()
for i, row in enumerate(rows):
    print "Row", i, "value = ", row

try:
    cur.execute ("""UPDATE versions SET status='stable' where version='2.6.0' """)
    cur.execute ("""UPDATE versions SET status='old' where version='2.4.4' """)
    db.commit()
except Exception, e:
    db.rollback()
```

### libpq: Postgresql C-language interface

```C
#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h”
static void exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

int main(int argc, char **argv)
{
    const char *conninfo;
    PGconn     *conn;  PGresult   *res;
    int         nFields;
    int         i,  j;

    conninfo = "port=5432 dbname='sibel' host='localhost' user='sibel' ";
    conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK)    {
        fprintf(stderr, "Connection to database failed: %s",
        PQerrorMessage(conn));
        exit_nicely(conn);
    }

    /* Start a transaction block */
    res = PQexec(conn, "BEGIN");

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
         fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
         PQclear(res);
         exit_nicely(conn);
    }
    /* Should PQclear PGresult whenever it is no longer needed to avoid memory leaks */
    PQclear(res);

    res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from pg_database");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    }

    res = PQexec(conn, "FETCH ALL in myportal");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    }
    /* first, print out the attribute names */
    nFields = PQnfields(res);
    for (i = 0; i < nFields; i++)
        printf("%-15s", PQfname(res, i));
    printf("\n\n");
    /* next, print out the rows */
    for (i = 0; i < PQntuples(res); i++)
    {
        for (j = 0; j < nFields; j++)
            printf("%-15s", PQgetvalue(res, i, j));
        printf("\n");
    }

    PQclear(res);

    /* close the portal ... we don't bother to check for errors ... */
    res = PQexec(conn, "CLOSE myportal");
    PQclear(res);

    /* end the transaction */
    res = PQexec(conn, "END");
    PQclear(res);

    /* close the connection to the database and cleanup */
    PQfinish(conn);

    return 0;
}
```

### Triggers

a trigger has:

1. a database event that must be true for the trigger to be activated (like insert of a class)
2. a condition that must be true for the trigger to be executed (like when a new tuple has code CSCI)
3. a method of execution for each row that is being changed and for each statement
4. a triggering time
   1. BEFORE - before the triggering change is executed
   2. AFTER - after the triggering change is executed and the result recorded
   3. INSTEAD OF - instead of the triggering event

- Triggers can be defined on tables or views.
- Triggers can be executed for each row being changed or a the whole statement.

::: info
Triggers become part of the transaction that triggered them

:::

#### Access to Changes

a trigger can access the old and new data through the OLD and NEW variables

- OLD: the tuple before the update
- NEW: the tuple after the update

::: warn
DELETE has no NEW and INSERT has no OLD

:::

::: info
Postgresql defines a function that returns a trigger first, then defines a trigger

:::

EXAMPLE:

```SQL
CREATE FUNCTION fix_favorites () RETURNS trigger AS $$
BEGIN
    IF NEW.result = 'star baker' THEN
       DELETE FROM favorites
       WHERE baker = NEW.baker AND episodeid = NEW.episodeid ;
    END IF ;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER fix_favorites AFTER INSERT OR UPDATE ON results
  FOR EACH ROW EXECUTE FUNCTION fix_favorites();

CREATE FUNCTION fix_baker () RETURNS trigger AS $$
BEGIN
  NEW.baker = initcap(trim(NEW.baker));
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER fix_baker BEFORE INSERT OR UPDATE ON bakers
FOR EACH ROW EXECUTE FUNCTION fix_baker();
```

### Views

- A view is a query
- Views can be anonymous

```SQL
SELECT *
FROM
   (SELECT baker, fullname, age
    FROM bakers
    WHERE baker not in (select baker
                        from results
                        where result = 'eliminated')
   ) as noteliminated
WHERE noteliminated.age > 45;
```

- The relation not eliminated above is an anonymous view (it is not known outside of this query)
- This query is combined with the remaining query to find the optimal query plan

EXAMPLE:

the query above after optimization might be:

```SQL
SELECT
   baker
   , fullname
   , age
FROM
   bakers
WHERE
   age > 45
   and baker not in (select baker from results where result = 'eliminated');
```

#### When to use anonymous views:

- the query cannot be written without it or it provides savings that are missed by the optimizer
- Otherwise, the optimizer may miss some optimizations and rewritings of the query when views are used

### Views (not anonymous)

a view with a name that can then be used elsewhere

```SQL
CREATE VIEW noteliminated(baker, fullnamename, age)
AS
SELECT baker, fullname, age
FROM bakers
WHERE baker not in (select baker
                    from results
                    where result = 'eliminated');
```

this can now be used like it was a table:

```SQL
SELECT *
FROM noteliminated
WHERE age > 45 ;
```

### Why use views?

##### compartmentalization

different users can only see the data that they have access to

EXAMPLE:

problem: faculty cannot access the financial information of students and can only access the information about the students who are currently taking the course with them

solution: create a view for students in a specific class with ONLY the relevant attributes, then build the application on top of that

Views can also be used to insert/update/delete tuples instead of the table they are based on.

- This builds on the philosophy of building functionality based on views
- However, this is only possible for a very restricted subset of views, called updatable views
- Updatable views are such that each tuple in the view maps to one and only one tuple in the table it is based on
- Using views to create functionality hides data complexity from developers 
  - If the data model changes, the application code does not have to change as long as the new model can be mapped to the same view

### Why not use views

- Writing a query using views may hide some optimizations from the database, creating sub-optimal query plans

### Updatable views

A view is updatable if:

- It has only one table T in its FROM clause
- It contains all attributes from T that cannot be null
- It does not have any DISTINCT, GROUP BY statements (one-to-one correspondence between a tuple in the view and a tuple in the table)

EXAMPLE:

```SQL
CREATE VIEW lt40(baker, fullnamename, age)
AS
SELECT baker, fullname, age
FROM bakers
WHERE age < 40;

UPDATE lt40 SET age = 40 WHERE baker = 'Manon' ;
```

- lt40 does not store any tuples. This expression allows only those tuples of bakers that are accessible through view to be updated.
- **After the update, the resulting tuple may not even be in the view (unless the view is created with the CHECK OPTION):**

```SQL
UPDATE lt40 SET age = 40 WHERE baker = 'Manon' ;
```

Since now Manon is not younger than 40, she will not be returned by the view

### 

Indexing

- Views don't improve performance, and may even cause a loss of performance
- One way to improve performance is to store (cache) the results of some queries in the database
- That's an index, just a cached query result

```SQL
SELECT episodeid
FROM technicals
WHERE baker = 'Kim-Joy' and rank = 1;
```

This requires reading the entire `technicals` table, and returns very little

#### Cost Analysis

- consider a large table X, and a query that returns a few tuples as the answer
- suppose X is stored on a disk in 100 disk pages, answering this query will take reading all 100 disks
- instead, use an Index on Technicals (baker) for the above syntax (or a similar index for relation X)
- this will make the cost just reading the tuples from the index, which is much less expensive

#### Indexing as views

- Indexes are just query results stored explicitly
- They are also stored on disk, but can be cheaper to use because: 
  - They have fewer disk pages as they store only a subset of the attributes in the relation
  - They are stored in a way to make it easy to find queries on specific values in the index

#### Index cost/benefit analysis

- Indices are good if 
  - they reduce the cost of frequently asked queries
  - the reduction is considerable
- Indices must be kept up to date when the tables change
- Indices increase the cost of insert/update/delete operations (at least one extra disk page access for each index created)
- a good index will reduce the total number of matching tuples to 1 or a few
- almost all databases will create an index on the primary key

EXAMPLE:  
an index on students(id) would improve queries like `SELECT * FROM bakers WHERE baker = 'Rahul';`

**If the underlying relation is sorted with respect to some attribute, then an index on that attribute will help performance**

EXAMPLE:

- Suppose, technicals tuples are sorted by baker and rank.
- Create an index on Technicals(baker, rank)

given this query

```SQL
SELECT
    episodeid
 FROM
    technicals
 WHERE
    baker = 'Kim-Joy'
    and rank = 1;
```

use the index to find the first tuple for `baker` 'Kim-Joy', and then scan the `technicals` relation starting from that point

### Access Structure

- A postgresql database cluster is organized into databases
- No data can be shared across databases
- Information in a database can be clustered into logical units called schema

#### Schema

create a schema using:

```SQL
CREATE SCHEMA schemaname;
```

access/create tables in the schema using:

```SQL
schema.table
```

delete a schema and everything inside it using:

```SQL
DROP SCHEMA schemaname;
```

create a schema owned by someone

```SQL
CREATE SCHEMA schemaname AUTHORIZATION username;
```

#### Search path

when a table is used, the db tries to find the correct instance
search path is usually (in order):

1. `\$user`: a schema with the same name as the current user
2. public: any information that is open to all users

::: info
the search path can be changed by using* `set search_path to ...`

:::

### Security

* postgres allows the creation of roles
* a role is like a user, but more general
* **a role with a login privilage is considered a user**
* a role can be given the right to create databases and/or create other roles
* a role with superuser privilages can bypass all security checks

#### Role Creation and Inheritance

`INHERIT` allows the role to inherit all the privilages given to that role?

```SQL
CREATE ROLE joe LOGIN INHERIT;
CREATE ROLE admin NOINHERIT;
CREATE ROLE wheel NOINHERIT;
GRANT admin TO joe;
GRANT wheel TO admin;
```

- Joe has privileges of admin on login because user Joe inherits from its roles. However, admin does not have the privileges assigned to wheel because it does not inherit (it is not inherited).
- As a role connects to the database, it has all the rights given to that role (login role). For other privileges that are not inherited, the user must explicitly set itself to that role using `SET ROLE admin ;`

### Database Objects

- all database objects (database, tables, indices, procedures, triggers, etc) have an owner (the role that created them)
- owner has all the access rights on the objects they create
- other role can be granted explicit privilages on these objects like `SELECT, INSERT, UPDATE, DELETE, TRUNCATE, REFERENCES, TRIGGER, CREATE, CONNECT, TEMPORARY, EXECUTE, and USAGE`
- SELECT, INSERT, DELETE, UPDATE are the privileges to query (select) and change the data of some other role. 
  - Can be specific: `SELECT(name)`
  - `REFERENCES` is the right to refer to a relation in an integrity constraint
  - `USAGE` is the right to use a schema element in relations, assertions, etc.
  - `TRIGGER` is the right to define triggers.
  - `UNDER` is the right create subtypes

#### Grant option

Users/roles can pass a privilege to another user/role is they have the grant option

```SQL
GRANT select ON users TO uname
WITH GRANT OPTION
```

::: info
Only a role that has a grant option can grant the grant option to the others.

:::

#### Grant diagrams

- Nodes represent a user and a privilege
- Two different privileges of the same person should be put in two different nodes
- If one privilege for a user is the more general version of another, they should both be included.

EXAMPLE: `select, select(name)`

Each grant generates a path in the grant diagram
Nodes are marked by:
\- \*\* for owners
\- \* for users who have grant option
\- nothing for all other users

![image (20).png](.attachments.34361/image%20%2820%29.png)

#### Adding privilages

- when a new role X is given by role A to role B
- if there are no nodes for (A,X) and (B,X), then create them
- add all the necessary links

#### Revoking privilages

- `revoke <privilages> on <database element> from <role list>`
- `cascade` will remove any privilages that are granted only because of the removed privilages
- `restrict`: will fail if the revoked privilages were passed on to other roles previously

this will also

- delete any edges corresponding to the deleted privilages
- if there are any nodes not reachable from the double starred node, then they should be removed along with all edges coming out of them

EXAMPLE

![image (21).png](.attachments.34361/image%20%2821%29.png)

### Case Statements in SELECT

```SQL
SELECT
  a,
  CASE WHEN a = 1 THEN 'one'
       WHEN a = 2 THEN 'two'
       ELSE 'other'
  END
FROM test;

 a | case
 ---+-------
 1 | one
 2 | two
 3 | other
```

### Group by extended

**Group by multiple groups**

```SQL
CREATE TABLE events (
    name     varchar(10)
    , day    varchar(10)
    , time   varchar(10)
   , price  INT
) ;

SELECT * FROM events;
name   | day | time  | price
----------+-----+-------+-------
sitting  | M   | 12:00 |     5
reading  | W   | 2:00  |    10
sleeping | M   | 2:00  |    12
hopping  | W   | 12:00 |     8
jumping  | M   | 4:00  |    22

SELECT
   day
   , time
   , count(*)
   , sum(price)
FROM
   events
GROUP BY
   GROUPING SETS ((day), (time), ());

day | time  | count | sum
-----+-------+-------+-----
M   |       |     3 |  39      --grouped by day
W   |       |     2 |  18      --grouped by day
    |       |     5 |  57      --grouped by everything
    | 12:00 |     2 |  13      --grouped by time
    | 2:00  |     2 |  22      --grouped by time
    | 4:00  |     1 |  22      --grouped by time
```

**Rollup**
does grouping in a hierarchical way, removing one attribute at a time

```SQL
ROLLUP (day,time)
-- will first group by (day,time), then by (day) alone, then by everything
```

**Cube will do group by every combination**

```SQL
CUBE (day, time)
-- will group by
-- (day,time)
-- (day)
-- (time)
-- ()
```

### Window Functions

Window functions compute aggregates without a group by for a window of values

```SQL
SELECT name, day, time, sum(price) OVER (partition by day)
FROM   events
ORDER BY day;

name   | day | time  | sum
----------+-----+-------+-----
sitting  | M   | 12:00 |  39
sleeping | M   | 2:00  |  39
jumping  | M   | 4:00  |  39
reading  | W   | 2:00  |  18
hopping  | W   | 12:00 |  18
```

### Group by with filter

Filter allows you to apply an aggregate to a subset of tuples in that group

```SQL
SELECT day
       , sum(price) as total
       , sum(price) filter (where price > 10) as totalfiltered
FROM events
GROUP BY day;

day | total | totalfiltered
-----+-------+---------------
 W   |    18 |
 M   |    39 |            34
```

### Recursive Queries

EXAMPLE:

```SQL
-- Recursive queries use the basis query to build on itself
SELECT * FROM parents ;

 parent  |  child
 ---------+---------
 Dakota  | Madison
 Madison | Ava
 Madison | Sophia
 Sophia  | Noah
 Noah    | Emma
```

EXAMPLE 2:

```SQL
-- Find all ancestral relations of degree 2 or higher
WITH RECURSIVE ancestors(ancestor, child, degree) AS (
      SELECT parent, child, 1 FROM parents
    UNION ALL
      SELECT a.ancestor, p.child, a.degree+1
      FROM ancestors a, parents p
      WHERE a.child = p.parent
)
SELECT ancestor, child, degree FROM ancestors WHERE degree >= 2;

ancestor | child  | degree
----------+--------+--------
Dakota   | Sophia |      2
Dakota   | Ava    |      2
Madison  | Noah   |      2
Sophia   | Emma   |      2
Dakota   | Noah   |      3
Madison  | Emma   |      3
Dakota   | Emma   |      4
```

### Embedded SQL Programming (ESQL)

- written in a non-SQL language, but uses SQL constructs
- requires programmers to work on low-level details of communications with the database
- first precompile using a special program, which will rewrite the program code by replacing pieces of it
- Once precompilation is finished, the remaining code is compiled
- Embedded SQL, ESQL is an industry standard language


* starts with `EXEC SQL` and ends with `;`
* all variables to be used by the program as input/output to a query must be declared within a declare section
* Often type conversion for preliminary data types between the programming language and SQL is done by hand
* Proc in Oracle, ECPG in Postgresql implements the C embeddings for SQL
* A pre-compiler will scan a program file and only read the statements enclosed within EXEC SQL statements and disregard everything else

EXAMPLE

```CPP
#include <stdio.h>
exec sql include sqlca;

char user_prompt[] = "Please enter username and password:  ";
char cid_prompt[] = "Please enter customer ID:  ";

int main()
{
    exec sql begin declare section;       /* declare SQL host variables    */
        char cust_id[5];
        char cust_name[14];
        float cust_discnt;                  /* host var for discnt value    */
        char user_name[20];
    exec sql end declare section;

    exec sql whenever sqlerror goto report_error; /* error trap condition     */
    exec sql whenever not found goto notfound; /* not found condition      */

    exec sql unix:postgresql://csc4380.cs.rpi.edu/sibel AS myconnection USER :user_name;
    /* ORACLE format: connect  */

    while (prompt(cid_prompt, 1, cust_id, 4) >= 0) {
        exec sql select cname, discnt
                into :cust_name, :cust_discnt   /* retrieve cname, discnt   */
                from customers where cid = :cust_id;
        exec sql commit work;                     /* release read lock on row */

        printf("CUSTOMER'S NAME IS  %s AND DISCNT IS  %5.1f\n",
             cust_name, cust_discnt);            /* NOTE, (:) not used here  */
        continue;
    }
}
```

#### SQLCA

a specific data structure for storing status codes of all SQL operations

```SQL
/* always have this for error handling*/
exec sql include sqlca ;
```

### Connections

To be able to perform any operations, first open a connection to the database

```SQL
EXEC SQL CONNECT TO target [AS connection-name] [USER user-name];
```

- many connection can be opened in a program, but generally one connection per database is sufficient
- different databases can be used in a single program
- if you want to close the connections (do this before the program exits) use `EXEC SQL DISCONNECT [connection];`
- change between multiple open connections using `EXEC SQL SET CONNECTION connection-name;`

#### Variables in ESQL

All variables **MUST** be declaired using ESQL declarations and data types

```SQL
EXEC SQL BEGIN DECLARE SECTION ;
VARCHAR    e_name[30], username[30] ;
INTEGER     e_ssn, e_dept_id ;
EXEC SQL END DECLARE SECTION ;
```

::: info
You can use almost any SQL command in ESQL as long as proper input to these commands are provided in the form of program variables

:::

### Executing SQL commands

EXAMPLE
find the name of an employee given their SSN

```SQL
EXEC SQL select name, dept_id into :e_name, :e_dept_id
	from employee
	where ssn = :e_ssn ;
```

::: info
Program variables are preceded by “:”, i.e. :e_ssn.

:::

#### Strings from Oracle to C

in Oracle, strings are stored along with the length, so no need for a terminating char
to use with C you must **MANUALLY ADD THE TERMINATING CHARACTER**

EXAMPLE:

```C
strcpy(username.arr, “Sibel Adali") ;
username.len = strlen(“Sibel Adali") ;
strcpy(passwd.arr, “tweety-bird") ;
passwd.len = strlen(“tweety-bird") ;
exec sql   connect :username  identified by :passwd ;
scanf(“%d", &e_ssn) ;
exec sql   select name, dept_id into :e_name, :e_dept_id
           from employee where ssn = :e_ssn ;
e_name.arr[e_name.len] = '\0' ;   /* so can use string in C*/
printf(“%s", e_name.arr) ;
exec sql commit work ;  /* make any changes permanent */
exec sql disconnect ;     /* disconnect from the database */
```

#### Status Processing

**<u>SQL Communications area (sqlca)</u>** is a data structure that contains information about

- error codes (might be more detailed than SQLSTATE)
- warning flags
- event information
- processed rows' count
- diagnostics for all processed SQL statements
- include it in the program using `EXEC SQL INCLUDE SQLCA;` or `#include <sqlca.h>`
- Whenever an SQL statement is executed, its status is returned in a variable named `"SQLSTATE"`
- this variable **MUST** be defined in the variable section, but the values are populated automatically

```SQL
EXEC SQL BEGIN DECLARE SECTION;
  char    SQLSTATE[6] ;
EXEC SQL END DECLARE SECTION;
```

::: warn
if multiple errors or warnings happen during the execution of a statement, sqlca will contain info about the last one

:::

- if no error or warning occurred in the last SQL statement, `sqlca.sqlcode` will be 0 and `sqlca.sqlstate` will be “00000”
- if an error or warning occured, then `sqlca.sqlcode` will be negative and `sqlca.sqlstate` will not be “00000”

::: info
if the stement was successful, then `sqlca.sqlerrd[1]` will have the OID of the processed row (if applicable) and `sql.sqlerrd[2]` will have the number of processed or returned rows (if applicable)

:::

The code can be checked after each statement and error handling code can be written

- commit, rollback, exit program, etc

```C
if (strcmp(SQLSTATE, "000000") != 0)
	rollback ;
```

you can use trap conditions that remain active throughout the program

```SQL
EXEC SQL WHENEVER <condition> <action> ;
```

- conditions: `SQLERROR`, `SQLWARNING`, `NOT FOUND`
- Actions: `DO function`, `DO break`, `GOTO label`, `CONTINUE`, `STOP`

::: error
what the hell is this???

\- Because WHENEVER is a declarative statement, its scope is positional, not logical. That is, it tests all executable SQL statements that physically follow it in the source file, not in the flow of program logic.

\- A WHENEVER directive stays in effect until superseded by another WHENEVER directive checking for the same condition.

:::

#### ESQL Transactions

- Transactions start with the logically start with the first SQL statement and end with either a COMMIT or ROLLBACK statement
- It is possible to set boundaries of transactions with the SQL statement:

  ```SQL
  BEGIN ;
  SET TRANSACTION READ ONLY
    ISOLATION LEVEL READ COMMITTED
    DIAGNOSTICS SIZE 6 ;
  ```
- Diagnostics size is the number of exception conditions that can be described at one time in the status
- READ ONLY, READ/WRITE transactions allow the programmer to define the type of the transaction

#### ESQL Cursor Operations

to declair a cursor, use a normal SQL query

```SQL
EXEC SQL DECLARE emps_dept CURSOR FOR
      select ssn, name from employee
      where dept_id = :e_dept_id ;
```

- Open a cursor: the corresponding SQL query is executed, the results are written to a file (or a data structure) and the cursor is pointing to the first row `EXEC SQL OPEN emps_dept ;`
- read the row the cursor is pointing to using `FETCH` (this also moves the cursor to the next row) `EXEC SQL FETCH emps_dept INTO :e_ssn, :e_name ;`
- when the cursor is done, `sqlca.sqlcode == -1
- handle errors using `EXEC SQL WHENEVER NOT FOUND {}`

#### Cursors and Snapshots

cursors can be declared as INSENSITIVE which means

- the contents are computed when the cursor is opened
- the contents will not change even if the database changes

::: info
This type of cursor is used for snapshots of the database

:::

```SQL
DECLARE cursor_name [INSENSITIVE][SCROLL] CURSOR FOR
  table_expression
  [ORDER BY order-item-comma-list]
  [ FOR [READ ONLY | UPDATE | OF column-commalist] ]
```

#### Cursors for Update

cursors can be declared for update which means:

- updates can be performed on the current tuple
- these updates will ONLY have an effect if the cursor is **NOT** insensitive

```SQL
DECLARE CURSOR cursor-name CURSOR FOR table-expression
            FOR UPDATE OF column-list

UPDATE table-name SET assignment-list
           WHERE CURRENT OF cursor-name

DELETE FROM table-name WHERE CURRENT OF cursor-name
```

#### Constraints

- throw an `sqlerror` if violated
- can be violated if 
  - if constraint checking is immediate, then a violation will trigger an immediate rollback
  - if constraint checking is deferrable, then a violation will do nothing until a transaction tries to commit, when it will be thrown and trigger a rollback

#### Dynamic SQL

- embedded SQL statements are created using strings
- strings are fed to an `EXEC` SQL statement `exec sql execute immediate :sql_string`
- statements are not known to the pre-compiler, and must be optimized at runtime
- you can use the same string to run multiple statements

EXAMPLE:

```SQL
strcopy(sqltext.arr, "delete from employee where ssn = ?") ;
sqltext.len=str.len(sqltext.arr) ;
exec sql prepare del_emp from :sqltext ;
exec sql execute del_emp using :cust_id ;
```

#### SQLDA

- when a dynamic SQL statement is executed, we don't know which columns will be returned/how many
- the SQLDA descriptor definition allows us to find the number of columns/their values

EXAMPLE:

```SQL
exec sql include sqlda ;
exec sql declare sel_curs cursor for sel_emps ;
exec sql prepare sel_emps from :sqltext ;
exec sql describe sel_emps into sqlda ;

exec sql open sel_curs ;
exec sql fetch sel_curs using descriptor sqlda ;
```

### SQL Object-Relational Frameworks

see [this link](https://dba-presents.com/other/my-thoughts/34-database-agnostic-applications) for more

- tight integration between application logic and the database
- describe the database model as an object-oriented class description
- write queries not in SQL but directly in the programming language
- Create tools that are DB agnostic (abstracts the database away)

![image (22).png](.attachments.34361/image%20%2822%29.png)

**Main Focus**

- handle repetitive and common tasks (data validation, input sanitation, etc)
- provide common tools for these tasks to make programs fast and easy to develop 
  - examples: auth tools, password/email data types

**Common use cases:**

- Django for Python: Disqus, bitbucket, instagram, pinterest
- Ruby on Rails or Grail for Ruby: airbnb, ask.fm, couchsurfind, github
- Hibernate for Java
- DataObjects.Net for .NET
- SQLAlchemy and Flask for Python

::: info
Examples below are based on Django

:::

#### MVC/T: Models, Views and Templates (or Controllers)

- build a full-stack app by defining the different compoenents 
  - models: data models of the tables that will be stored in the database
  - views: HTML pages (load data and execute functions for actions, i.e button clicks)
- views are often a mix of HTML/Python and Javascript for active elements

**Models**

- define DB tables using an object-relational paradigm
- each table is a class which stores objects of this type

EXAMPLE:

```python
class Student(models.Model):
    name = models.CharField(max_length=255)
    email = models.CharField(max_length=255)
    address = models.CharField(max_length=255)
    year = models.IntegerField()
    gpa = models.FloatField()
    major = models.CharField(max_length=2)
```

*The associated table will be called Students and have primary key id by default (can be overridden)*

**Views**

- views can query these objects using simple queries
- Templates can render these objects using simple loops

EXAMPLE:

```python
# This is a View
def index(request):
    students = Student.objects.all()
    return render(request, 'index.html', {'students':students,})
```

EXAMPLE 2:

```HTML
<!-- This is a Template -->
<ul>
  {% for student in students %}
    <li><b>{{ student.name }}</b>:</li>
       <ul>
        <li>ID: {{student.id}}</li>
        <li>Address: {{student.address}}</li>
        <li>Email: {{student.email}}</li>
        <li>Year: {{student.year}}</li>
       <li>GPA: {{student.gpa}}</li>
     </ul>
  {% endfor %}
</ul>
```

**Complex Models**
Can have foreign keys

```python
class Department(models.Model):
    name = models.CharField(max_length=255)
    office = models.CharField(max_length=40)
    phone = models.CharField(max_length=12)

class Major(models.Model):
    name = models.CharField(max_length=255)
    department = models.ForeignKey(Department, on_delete.Models.CASCADE)
```

Allows for querying and retrieval of models through foreign keys

```python
departments = Deparment.objects.all()
majors = Major.objects.all()
for major in majors:
    print (major.department.name)

majors = Major.objects.filter(department__name = 'Computer Science')
```

#### Querying

- most queries are simple filter statements over single relations or relations through foreign keys
- do not require full knowledge of SQL
- most application functions are easily mapped to CRUD operations (create, read, update and delete)

::: warn
Be careful if your join is different than what the foreign key impliesBe careful about how much data is read for each object and when: for deep nested structures, does it read the whole hierarchy?

:::

### SQL Object-Relational Extensions

- postgres (and others) have extensions that go beyond the relational data model
- these violate the relational data model
- trades simplicity of data/model queries for harder optimizations
- find where an extension is using `SELECT * FROM pg_available_extensions WHERE name = 'extension_name_here';`

#### Semantic Hierarchies and Inheritance

same as `ISA` (is a) relationships in ER diagrams (i.e. A isa B, which means it has all of B's attributes and then it's own)

CLASS HIERARCHIES EXAMPLE:

```SQL
CREATE TABLE cities (
     name            text
     , population    float
     , altitude      int     -- in feet
);

CREATE TABLE capitals (
     state           char(2)
) INHERITS (cities);
```

if you now do

```SQL
SELECT name, altitude
FROM cities
WHERE altitude > 50;
```

the above will query all cities AND all capitals

use the **ONLY** attribute to only query cities, not capitals

```SQL
SELECT name, altitude
FROM ONLY cities
WHERE altitude > 50;
```

To find out which table a row comes from use the `relname` attribute from the `pg_class` table

```SQL
SELECT p.relname, c.name, c.altitude
FROM cities c, pg_class p
WHERE
    c.altitude > 50
    and c.tableoid = p.oid;

Output:
relname   |   name    | altitude
----------+-----------+----------
cities    | Las Vegas |     2174
cities    | Mariposa  |     1953
capitals  | Madison   |      84
```

#### Complex Objects/User Defined Types

::: warn
This goes against the first normal form (i.e that all values should be atomic), but it allows multiple related values to be encapsulated

:::

```SQL
CREATE type phone_type AS (
     num varchar(12)
     , type varchar(50)
);

CREATE TABLE person (
     id int
     , name varchar(30)
     , phone phone_type
) ;

INSERT INTO person VALUES(
     1
     , 'Kara Danvers'
     , ('555-1234','work')::phone_type
) ;

SELECT * FROM person WHERE (phone).type = 'work';

 id |     name     |      phone
----+--------------+-----------------
 1 | Kara Danvers | (555-1234,work)
```

::: info
you can define user defined types to be restricted domains of values and then use in multiple places

:::

### Collection of Values

#### Arrays

```SQL
CREATE TABLE messages (
     msg  text[]
) ;

INSERT INTO messages VALUES ('{"hello", "world"}') ;
INSERT INTO messages VALUES ('{"I", "feel", "so", "free"}') ;

SELECT msg[2] FROM messages ;  --not zero indexed
msg
-------
world
feel
(2 rows)

SELECT msg[2:3] FROM messages; --slicing, really?

msg
-----------
{world}
{feel,so}
(2 rows)
```

::: info
The best of use complex types is to write procedures/functions using pl/pgsql or a programming language like C.

:::

### Typed objects and methods

- main use is to create extensions for handling specific types of data
- Examples: 
  - Geographic data: points (geo locations), polygons (state, city boundaries), line segments (roads, rivers)
  - Text data: vectors of words and weights for each word
  - JSON

    ```SQL
    SELECT '{"foo": {"bar": "baz"}}'::jsonb;
      jsonb
      -------------------------
      {"foo": {"bar": "baz"}}
      
      SELECT '{"foo": {"bar": "baz"}}'::jsonb->'foo';
      
      ?column?
      ----------------
      {"bar": "baz"}
    ```

#### Geographic Data

- use PostGIS, an extension that supports geographic data
- this is an EXTERNAL PACKAGE AND MUST BE INSTALLED FIRST (i.e. `yay -S postgis`) The way to install postgres in the course notes is out of date, use this instead ([source](http://obsessivecoder.com/2010/02/01/installing-postgresql-8-4-postgis-1-4-1-and-pgrouting-1-0-3-on-ubuntu-9-10-karmic-koala/))

```sh
sudo su postgres
createdb template_postgis
createlang plpgsql template_postgis
psql -d template_postgis -f /usr/share/postgresql/8.4/contrib/postgis.sql
psql -d template_postgis -f /usr/share/postgresql/8.4/contrib/spatial_ref_sys.sql
```

you can now use all the data types and methods available in postgis
EXAMPLE:

```SQL
CREATE TABLE bwithloc (
     name  VARCHAR(100)
     , location geography(POINT,4326)
) ;

insert into bwithloc values('Rensselaer Polytechnic Institute',
     ST_GeographyFromText('SRID=4326;POINT(42.7308634 -73.6816793)'));

insert into bwithloc values('Shalimar Restaurant',
     ST_GeographyFromText('SRID=4326;POINT(42.732293 -73.688473)'));

insert into bwithloc values('The Placid Baker',
     ST_GeographyFromText('SRID=4326;POINT(42.7313916 -73.690868)'));
```

- SRID shows the projection used to compute the latitude and longitude
- you can also enter polygons as arrays of points, line segments are arrays of lines, etc
- many geography functions are available (distance is in meters) EXAMPLE:

```SQL
SELECT b1.name, b2.name, ST_DISTANCE(b1.location, b2.location)
FROM bwithloc b1, bwithloc b2
WHERE b1.name < b2.name ;
```

### Text Querying

- postgres supports text processing

EXAMPLE:

```SQL
SELECT to_tsvector('fat cats ate fat rats');

-- numbers show the location of the keyword in the text.
to_tsvector
-----------------------------------
'ate':3 'cat':2 'fat':1,4 'rat':5
```

- supports some boolean operations

LARGE EXAMPLE:
You can search a keyword query in a document by relevance. The number of times a word appears will increase the relevance of the text to the query

```SQL
SELECT
   b.name
   , ts_rank_cd(to_tsvector('english', r.review_text), query) AS rank
FROM
   reviews r
   , businesses b
   , to_tsquery('pizza & (crust | sauce) & (delicious|tasty)') query
WHERE
   b.business_id = r.business_id
   and to_tsvector('english', r.review_text) @@ query
ORDER BY rank DESC
LIMIT 10;

            name            |   rank
----------------------------+-----------
 DeFazio's Pizzeria         |      0.05
 Little Bites and More      |      0.05
 Notty Pine Tavern          | 0.0366667
 Red Front Restrnt & Tavern | 0.0285714
 New York Style Pizza       |     0.025
 Milano Restaurant          | 0.0218698
 DeFazio's Pizzeria         | 0.0202986
 The Fresh Market           |      0.02
 Dante's Pizzeria           | 0.0192982
 Labella Pizza              | 0.0155556
```

## Indexing

- databases are mainly optimized for data that is too large to fit in memory
- secondary storage is crucial for understanding: 
  - how data is accessed to respond to queries and modify data
  - how indices can help speed up queries and the performance trade-offs of using them

### Secondary Storage

::: info
the first part of this section is not sql. If you want to skip to the part about tuple storage and indices, jump to <a href="#tuple-storage-on-disk">Tuple Storage on Disk</a>

:::

#### Types of Disks

- **Magnetic Disks**: 
  - Cost-effective with high capacity.
  - Characteristics: 
    - Inexpensive storage.
    - Fast sequential access.
    - Slower random access.
    - Density increases over time without significant speed improvements.
- **Solid State Drives (SSDs)**: 
  - Faster access and lower power consumption.
  - Characteristics: 
    - Rapid access for most operations.
    - Higher cost (~2x per TB compared to magnetic disks).
    - Typically smaller maximum capacity.
    - Cost gap with magnetic disks is narrowing.

#### Disk Structure

- **Components**: 
  - Multiple platters with two surfaces each.
  - Read/write heads access surfaces simultaneously.
  - Concentric tracks on each surface; identical tracks across surfaces form a cylinder.
  - Tracks divided into sectors (smallest operable unit for read/write).
  - Disk blocks are groups of consecutive sectors, sized to match memory page sizes (1K to 8K).

#### Disk Access

- **Steps to Read a Page**:
  1. **Seek Time**: Time to move the disk arm to the correct track.
  2. **Rotational Latency**: Time for the desired sector to rotate under the head.
  3. **Transfer Time**: Time to read the page into memory.

  **Formula**: `Total Read Cost = Seek Time + Rotational Latency + Transfer Time`
- **Performance Metrics**:
  - Seek Time: Average ≈ 6.46 ms.
  - Rotational Latency: Average ≈ 4.17 ms (7,200 RPM).
  - Transfer Time: ≈ 0.03 ms per sector (8.33 ms/256 sectors).

  **Example for an 8K page** (2 sectors): `Total ≈ 6.46 ms (Seek Time) + 4.17 ms (Rotational Latency) + 0.06 ms (Transfer Time) ≈ 10.69 ms

#### **Optimizing Disk Access**

- Reading multiple consecutive pages on the same track or cylinder amortizes seek and latency costs.
- Example for 100 consecutive pages on the same track:    `Total ≈ 6.46 ms (Seek Time) + 4.17 ms (Rotational Latency) + (100 * 0.03 ms) ≈ 13.63 ms`

#### **Disk Scheduling**

- Disk controllers may reorder requests to minimize seek times.
- **Elevator Algorithm**: 
  - Processes requests in one direction before reversing, reducing total movement

---

#### **Reliability with RAID**

- **RAID (Redundant Array of Independent Disks)** enhances performance and data reliability: 
  - **RAID-0 (Striping)**: Improves read performance by distributing data across disks; no redundancy
  - **RAID-1 (Mirroring)**: Duplicates data across disks for redundancy and faster reads
  - **RAID-4**: Uses a parity disk for error checking and data reconstruction in case of failure
  - **RAID-5**: Distributes parity information across all disks for balanced performance and reliability
  - **RAID-6**: Extends RAID-5 with additional parity for higher fault tolerance

### Tuple Storage on Disk

- a disk usually stores multiple tuples although large tuples may span multiple disks
- tuples have a physical address which contains the relevant subset of: 
  - Host name
  - Disk number
  - Surface number
  - Track number
  - Sector number
- Physical address tends to be long
- Tuples are also given a logical address in the relation,
- A map table stored on disk contains the mapping from the logical address to physical address
- When tuples are brought from disk to memory, its current address becomes a memory address
- Pointer swizzling is the act of changing physical address to the memory address in the map table for pages in memory

::: info
the number of tuples that can fit in a page is determined by the number of attributes and the type of attributes the relation has

:::

![image (23).png](.attachments.34361/image%20%2823%29.png)

- header information contains LOG data (when the data on the page was updated and other control information)

### Indices as Secondary Access Methods

- a table is a primary access method (i.e. to find a tuple in a table we need to search the whole table)
- an index is a secondary access method, which allows us to search the table for a search key
- the search key can contain multiple attributes
- the index contains pointers to tuples (logical address)
- the index is put into pages and stored on a disk

#### Dense vs Sparse Indices

- the index is dense if it contains an entry for each tuple in the relation
- an index is called sparse if it does not
- a sparse index is possible if the relation is sorted with respect to the index key

**Dense Index Example**
table T(A,B) is stored in two pages

```SQL
Table T P1:  (t1:[21,a], t2:[12,b], t3:[8,c], t4:[4,d])
Table T P2:  (t5:[31,e], t6:[35,f], t7:[10,g], t8:[1,h])
```

and we create an index I1 on T(A) which is also stored in two pages

```SQL
Index I1 PX:  (1,t8/P2), (4,t4/P1), (8,t3/P1), (10,t7/P2), (12,t2/P1)
Index I1 PY:  (21,t1/P1), (31,t5/P2), (35,t6/P2)
```

- The index may be able to store more information in each page because it only stores the search key and the pointer to tuple.
- If we were to search for a B value, the index is not useful.
- If we search for an A value but return B, then the index is partially useful

EXAMPLE

```SQL
SELECT B FROM T WHERE A=4;
```

this will then search the index to find the value that's stored in `t4`, then return the B value from said tuple

**Sparse Index Example**
imagine table T is stored and sorted by B explicitly

```python
Table T P1:  (t1:[21,a], t2:[12,b], t3:[8,c], t4:[4,d])
Table T P2:  (t5:[31,e], t6:[35,f], t7:[10,g], t8:[1,h])
```

We can create a different type index I2 on T(B)

```python
index I2 Page P5: (_,P1), (e,P2)
```

- this will say that values less than e for B, go to page P1, otherwise go to P2
- we won't necessarily know if a B value is stored by simply looking at the index
- BUT the index is much smaller, making it less costly to search

#### Multi-level Indices

- lowest level is the index pointing towards the tuples
- uppers point to the lower level index pages 
  - these are often sparse as the lowest level is sorted by key?

EXAMPLE:
convert the above index I1 to a multi-level index

```python
Index I1 PX:  (1,t8/P2), (4,t4/P1), (8,t3/P1), (10,t7/P2), (12,t2/P1)
Index I1 PY:  (21,t1/P1), (31,t5/P2), (35,t6/P2)

Index I1 PZ:  (_,PX), (21,PY)
```

to search, we start at the top level of the index (PZ), which tells us which lower index page to go to

```SQL
SELECT B FROM R WHERE A=31

-- Read index page PZ: Decide we must read index page PY
-- Read index page PY: Decide we must data page P2
-- Read data page P2: Find tuple t5, return the B value: e.
```

## B-Trees

- sometimes referred to as B+- trees
- binary trees, except instead of 2 (binary), they have often between n/2 to n entries

#### Properties of Main Tree
- each node is mapped to a disk page
- is in order of n (but n might change depending on different properties)

#### Properties of Leaf Nodes
- point to next node in the leaf (sibling node)
- can contain: 
  - at most n tuples (n values and pointers)
  - ONE additional pointer to the sibling node
- must contain at least `floor((n + 1) / 2)` **tuples** (plus the additional pointer)

#### Properties of Internal Nodes
- can contain at most `n + 1` pointers and n values
- must contain: 
  - at least `floor((n + 1) / 2)` **pointers**
  - the above minus one key values
- the exception is the *root*, which can contain a single key value and two pointers

![image (24).png](.attachments.34361/image%20%2824%29.png)

a b-tree created on search key A will have dense leaf nodes sorted by A
the internal nodes will be sparse indices to lower levels

EXAMPLE:

![image (25).png](.attachments.34361/image%20%2825%29.png)

given `n = 3`
- each leaf node will have between 2 and 3 tuples (inclusive)
- each internal node will point to between 2 and 4 nodes below (and so have between 1 and 2 key values)

given `n = 99`
- each node will have between 50 and 99 tuples (inclusive)
- each internal node will point to between 49 and 100 nodes below (and will have between 49 and 99 values)

**note that the root can have two pointers and one key value at least**
#### Searching in B-trees
**searching for equality `A = x`**
1. start at root
2. while (not leaf node)
	1. find the first key *greater* than x
	2. follow the pointer just before this key
3. if the leaf:
	1. contains key value x: return x's tuple id
	2. does not contain x: return empty

**Searching for range**
Given an index on attribute A find all tuples in the range `x1 <= A <= x2`
1. start at root
2. while (not leaf node)
	1. find the first key value that is greater than `x1` and less than `x`
	2. follow the pointer before this key value
3. while (leaf node values < `x2`)
	1. find all entries in leaf node in the given range
	2. retrieve next leaf node (sibling pointer) and continue
4. return all found tuple ids

#### Index on multiple attributes A,B
an index on multiple attributes A,B will sort first by A then by B
EXAMPLE:
- `A = x AND b = y`: same as searching `A = x` for index on A
- `A = x:
	 1. search for first value with `A = x` (ignore B)
	 2. scan leaf nodes to the right (following sibling nodes)
- `A = x AND y1 <= B <= y2`:
	 1. search only for `x1 <= A`
	 2. scan leaf nodes for `x1 <=  <= x2` following sibling nodes
	 3. for every leaf node found, check if `B = y`
		 1. if it is, put it in the output
- `B = y`
     1. find the first leaf node, scan all following leaf nodes following sibling nodes
     2. for each tuple:
	     1. if `B = y`, add to output
	 - THIS IS AN INDEX ONLY SCAN

#### Index-only Search
Given
```SQL
SELECT A FROM R WHERE A < 120 AND A > 10
```
and an index on `R.A`, scan the index for matching tuples and return the found A values

#### Index partial match
- Given an index on R(A,B) (index is sorted on A first and then on B)
	- `select C,D from R where A > 10 and A < 100 and B=2`
- Scan index for the range A > 10 and A < 100, and for each matching tuple check the B value, read matched tuples from disk for C,D attributes

### B-Trees with Duplicate Values
if a B-tree is build on a key/value that contains duplicates, it's built in the same way except:
- **Key Adaptation in Non-Leaf Nodes**:
    - When a **non-leaf node** points to a **leaf node**, the value stored in the non-leaf node should help distinguish between different keys.
    - If there are duplicates, instead of storing just the repeated key, it stores:
        - The **key value of the first unique key** (i.e., the first key in the leaf node that differs from its previous sibling node).
        - This helps maintain a clear path for searching and navigating.
- **Handling No Unique Keys**:
    - If **no unique key exists** in the leaf node (e.g., all entries in a particular range are duplicates), a **null value** is stored in the non-leaf node.
    - This null value indicates there’s no distinguishing key in this branch, and the traversal may rely on other branches or methods to continue the search.


#### Insertion
1. start from root
2. check if the resulting operation splits the root node
3. if it does (the node has more than n nodes in it)
    1. split the root node into two nodes
    2. promote the middle key to become the new root
    3. adjust the tree's height by one level to accommodate the new root (move new root to top, connect other nodes to the new root)
4. if it doesn’t, navigate to the appropriate child node based on the key to be inserted
5. repeat the process recursively:
    1. check if the target child node (where the key should be inserted) becomes full
    2. if the child node is full:
        1. split the child node into two nodes
        2. promote the middle key of the child node to the parent node
        3. redistribute the remaining keys and pointers between the two resulting nodes
6. insert the key into the appropriate node once a non-full node is found
7. ensure all properties of the B-tree (sorted order, maximum keys per node, and balanced structure) are maintained

1. **Duplicate Values**: Normally, B-trees store unique keys, and non-leaf nodes store keys to guide the search. However, when keys can repeat (e.g., two entries have the same key), you need a strategy to avoid confusion during indexing.
    
2. **Key Adaptation in Non-Leaf Nodes**:
    - When a **non-leaf node** points to a **leaf node**, the value stored in the non-leaf node should help distinguish between different keys.
    - If there are duplicates, instead of storing just the repeated key, it stores:
        - The **key value of the first unique key** (i.e., the first key in the leaf node that differs from its previous sibling node).
        - This helps maintain a clear path for searching and navigating.
3. **Handling No Unique Keys**:
    - If **no unique key exists** in the leaf node (e.g., all entries in a particular range are duplicates), a **null value** is stored in the non-leaf node.
    - This null value indicates there’s no distinguishing key in this branch, and the traversal may rely on other branches or methods to continue the search.

EXAMPLE:
Imagine a B-tree storing duplicates of the key `10`:
```markdown
Non-leaf node:
| 10 (points to leaf nodes) |

Leaf nodes:
| 10, 10, 10 | 10, 10, 11 | ...
```
- In this case, the non-leaf node:
    - Points to the first key `10` in the first leaf.
    - Then points to the **first non-repeating key** (`11`) for the second leaf.
    - If no non-repeating key existed in any sibling, a `null` would be stored instead.


#### Deletion
like insertion, but backwards
- if there are not enough keys in a node then borrow from neighbor
- if borrowing would break tree structure:
	- restructure the child nodes so that it maintains the correct order
- if this results in less than the min values in a node
	- merge the node with a neighbor or parent

EXAMPLE:
- Given:
	- disk page has capacity of 4K bytes
	- each tuple address takes 6 bytes and each key value takes 2 bytes
	- each node is 70% full
	- need to store 1 million tuples
	- Leaf node capacity:
	    - each (key value, tuple address) pair takes 8 bytes
- disk page capacity is 4K, so (4*1024)/8 = 512 (key value, rowid) pairs per leaf page
	- *in reality there are extra headers and pointers that we will ignore*
- Hence, the minimum number of pointers for the tree is 256
- If all pages are 70% full, each page has about 512*0.7 = 359 pointers
- To store 1 million tuples, requires
    1,000,000 / 359 = 2786 pages at the leaf level
    2789 / 359 = 8 pages at next level up
    1 root page pointing to those 8 pages
- Hence, we have a B-tree with 3 levels

### R-trees
- used for searching along two axes
	- `x1 <= A <= x2 and y1 <= B <= y2`
	- the second range here is not useful in determining the number of nodes
- similar to a B-tree except each key value in an internal node is a rectangle and contains a pointer to values and rectangles within that rectangle

### Bitmaps and Converted Indices
- text valued attributes must be preprocessed before indexing
	- this assures that the text fields an words are indexed as well
- a listing file for each word is made
  ```
	  word-> (tupleid, location within tuple), ...
	  -- EXAMPLE
	  pizza -> t1,2 t1,5 t3,4 t5,12
	```
- each inverted listing is then compressed and stored
- a boolean keyword query is processed by bitmap operations (bitwise AND, bitwise OR) over these vectors
	- Postgresql GIN structures are used for this purpose and text querying.
	- Other open source implementations of inverted files such as Apache Lucene project exist.
	- Google main index is a distributed and replicated inverted index over the Web documents.

### Primary and Secondary Indices
- index structure can be secondary
	- index pages containing pointers to tuples in data pages which are at a leaf level?
- Primary B-tree indices are also possible
	- internal nodes contain pointers to lower levels
	- leaf level contains data pages for the table
- THERE CAN ONLY BE A SINGLE PRIMARY INDEX
	- you can use clusters in postgres to generate primary indices

### Hashing
- often a primary index method
- given a has function h with K values and attribute A
	- allocated a number of disk blocks M to each bucket
	- for each tuple t, apply `h(t.A) = x`
	- store t in the blocks allocated for bucket x
- to search for an attribute A (`SELECT * FROM r WHERE r.a = c`) do
	- apply has function `h(c) = y`
	- read the buckets from y to find value c
	- will search `M / 2` pages on average and all pages in the worst case
- to search on another attribute
	- hashing is useless, search all disk pages
- insertion cost:
	- 1 read (find the last page in the appropriate bucket)
	- 1 write (store)
    
- deletion/update cost:
	- M/2 (search cost)
	- 1 (update cost)
- if a bucket has too many tuples, than the allocated M pages may not be sufficient
    - allocate additional overflow area
    - if the overflow area is large, the benefit of the hash is lost

### Extensible Hashing
- a dynamic hashing technique that adjusts its structure to handle dataset growth/shrinkage efficiently.

#### Key Concepts
- **Hash function and bit representation**
    - uses a hash function `h` to compute binary hash values for keys.
    - the first `z` bits of the hash value determine the directory index.
- **Directory structure**
    - the directory is an array of pointers to buckets containing the data.
    - directory size is `2^z`, corresponding to the `z` bits used from the hash value.
- **Bucket overflow and splitting**
    - if a bucket overflows:
        - check if the bucket's local depth < global depth.
            - split the bucket and redistribute entries.
        - if local depth = global depth:
            - double the directory size (increasing global depth by 1).
            - redistribute entries into new directory structure.

#### Advantages
- **Dynamic directory expansion**
    - grows as needed, maintaining efficient data access without performance loss.
- **Efficient space utilization**
    - splits only buckets that overflow; directory grows incrementally.

#### Considerations
- **Implementation complexity**
    - requires careful handling of dynamic directories and bucket splits.
- **Memory usage**
    - directory may consume significant memory for rapidly growing datasets.

#### Insertion
- find the correct bucket using `h(key)`.
- if the bucket overflows:
    - split the bucket and redistribute data.
    - potentially expand the directory if required.

#### Deletion/Update
- deletion cost:
    - locate and remove the tuple (similar to a search).
- update cost:
    - search for the tuple and update its value.

#### Performance Notes
- avoids performance degradation typical of static hashing with overflow areas.
- particularly useful for database systems with unpredictable dataset sizes.


### Linear Hashing
- a dynamic hashing technique that grows or shrinks incrementally, one bucket at a time.

#### Key Concepts
- **Hash functions and bucket allocation**
    - utilizes a family of hash functions, `h_i`, where each function determines the bucket index.
    - starts with an initial hash function, `h_0`, mapping keys to a fixed number of buckets.
    - as the dataset grows, switches to higher-level hash functions (`h_1`, `h_2`, etc.).
- **Dynamic expansion**
    - triggered when the load factor exceeds a threshold.
    - splits a bucket determined by a split pointer `s`.
    - split pointer increments linearly and resets when all buckets are split.
    - when the pointer resets, the hash level `l` increments, doubling addressable bucket space.
- **Dynamic contraction**
    - triggered when the load factor falls below a threshold.
    - merges buckets starting from the split pointer `s` with their counterparts.
    - decrements the level `l` when all buckets have been merged.

#### Operations
- **Insertion**
    - compute bucket index using hash function for level `l`.
    - if the index < split pointer `s`, rehash with the function for level `l + 1`.
    - insert record into the identified bucket.
    - if the load factor exceeds the threshold, split a bucket.
- **Search**
    - compute initial bucket index using the hash function for level `l`.
    - if the index < split pointer `s`, rehash with the function for level `l + 1`.
    - search in the identified bucket.
- **Deletion**
    - locate the bucket using the search procedure.
    - remove the record.
    - if the load factor drops below the threshold, merge buckets.

#### Advantages
- **Gradual resizing**
    - grows or shrinks one bucket at a time, avoiding large-scale rehashing.
- **Efficient space usage**
    - maintains an optimal load factor, balancing storage and performance.

#### Considerations
- **Implementation complexity**
    - managing split pointer, multiple hash functions, and resizing operations adds complexity.
- **Performance implications**
    - temporary uneven bucket sizes during splitting can affect access times.

#### Notes
- linear hashing is particularly suited for database systems where data sizes can change unpredictably, balancing flexibility and efficiency.

## Query Processing
- SQL queries are converted to bag relational algebra queries to be implemented
Overall picture of the DBMS system components
![[Pasted image 20241201144514.png]]
MOVE TO NEXTCLOUD????

#### Disk Access Process (Overly Simplified)
- to process any data, it must first be brought to memory
- Some DBMS component indicates it wants to read record R
    - File Manager:
	    - Does security check
	    - Uses access structures to determine the page it is on
	    - Asks the buffer manager to find that page
        
    - Buffer Manager
	    - Checks to see if the page is already in the buffer
	    - If so, gives the buffer address to the requestor
	    - If not, allocates a buffer frame
	    - Asks the Disk Manager to get the page
        
    - Disk Manager
	    - Determines the physical address(es) of the page
	    - Asks the disk controller to get the appropriate block of data from the physical address
	    - Disk controller instructs disk driver to do the dirty job

#### Resources
*Note: PAGES(R) is the total number of pages in relation R*
- An SQL is translated into a combination of relational algebra operations
- each operation is given M memory blocks to use

### Iterator Interface
- operators in the database are implemented using three main functions:
	 1. `open()`:
		 1. initialized the M memory buffers and/or streams
	 2. `getNext()`:
		 1. reads and processes data input streams until a block of output is created or the input is fully processed
		 2. puts the output to the output buffer
	3. `close()`:
		1. frees all structures used by the operator

- since all operators work the same, we can use the output buffer of an operation as the output buffer of the previous one
	- if this is the last operation, then the output buffer would just be standard out

EXAMPLE:
- suppose we are processing `select * from R where C` by scanning relation R
- SCAN(R, C):
	- `open()`:  reads the location of R's data pages and allocates the needed memory (at least M = 1 block is needed)
	- `getNext()`: reads blocks of R, for each tuple, if it satisfies the condition C:
		- move it to the output buffer until the output block is full
		- copies the output block to the output stream once it is full
	- `close()`: frees all the memory used for this operation

### Operator Classes
query operators are classified into classes
1. One pass
2. Two pass
3. Multi pass
depending on the availability of memory, storage method of the relation (i.e. sortedness for example) and the number of pages it occupies on disk

#### One pass algorithms
- require one pass over a given relation

**Duplicate Removal**



EXTERNAL SORT
to get the number of runs, divide the total number of pages by M, then if:
1. result > M, re-run until it isn't
2. one run is enough

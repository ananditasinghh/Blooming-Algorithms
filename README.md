# GardeningAndDSA

The intution for this project came from my personal gardeneing experience. It is always crucial to carefully plan and optimize the layout of a garden.
Considering the growth patterns and sunlight requirements of each plant before deciding where to place them. Observing how certain plants grow taller or wider, and how some prefer full sun while others thrive in partial shade, all of this has taught me the importance of providing adequate space and sunlight for each plant to flourish. I have also discovered the benefits and the concept of companion planting, where certain plants thrive when grown together, while others may hinder each other's growth.

Incorportating these personal observations and learnings, I have made GardeningAndDSA project, which uses the concept of Dynamic Programming and helps users optimize the layout of plants in a garden based on their growth patterns, sunlight exposure, and companion plant preferences. 

After gathering the plant information, the program calculates the optimal garden layout using the optimizeGardenLayout function. It then displays the optimal layout and calculates the total sunlight exposure of the chosen plants. The user is given the option to enter the name of a plant to display its details.

The program utilizes structures and vectors to store the plant information and the optimal layout. It also uses unordered sets to store the companion plants for each plant. The displayPlantDetails function retrieves and displays the details of a specific plant based on the user's input.

The three key features of this project are:

Garden Layout Optimization: The project utilizes dynamic programming to calculate the optimal arrangement of plants in the garden based on their growth patterns and the available garden size. By considering the growth patterns of plants and the space available, it suggests an optimized garden layout that maximizes the utilization of space and ensures plants have enough room to grow.

Companion Planting: The project incorporates the concept of companion planting, where certain plants have positive interactions when grown together. It allows users to specify companion plants for each plant, and during the optimization process, it considers these preferences. The algorithm checks for companion plants and adjusts the layout to place compatible plants together, fostering beneficial relationships and promoting the overall health and productivity of the garden.

Plant Details and Sunlight Exposure Calculation: The project enables users to input detailed information about each plant, including their names, growth patterns, sunlight exposure values, and companion plants. It also calculates the total sunlight exposure of the chosen plants in the optimal layout. This feature helps users make informed decisions about plant selection and ensures that plants with similar sunlight requirements are grouped together, maximizing their chances of thriving in the garden.


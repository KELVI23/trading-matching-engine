# Trading Matching Engine with Candlestick Graph

## Overview
This project implements a trading matching engine with added functionality for visualizing market data using candlestick graphs. The matching engine facilitates the trading of various cryptocurrency pairs by allowing users to place bids and asks, view exchange statistics, and analyze trading data through text-based plots.

## Features
1. **Matching Engine**: The core functionality of the system includes matching bids and asks for different cryptocurrency pairs based on price and time priority.

2. **Exchange Statistics**: Users can view exchange statistics such as the minimum ask and maximum ask for each product to gain insights into market dynamics.

3. **Bid/Ask Placement**: Traders can place bids and asks for specific cryptocurrency pairs, specifying the price and amount they are willing to trade.

4. **Text-Based Plots**: The system offers text-based plots for visualizing trading data. This includes plotting volume data and price data using appropriate characters to represent data points.

5. **Candlestick Graph**: A key feature of the system is the ability to generate candlestick graphs, providing a visual representation of price movements over time for a given cryptocurrency pair.

## Development Cycle
1. **Requirements Gathering**: The project requirements were identified, including the need for a trading matching engine, exchange statistics, and data visualization capabilities.

2. **Design and Architecture**: The system architecture was designed to accommodate the matching engine, data storage, and visualization components. Object-oriented principles were employed for modularity and extensibility.

3. **Implementation**: The matching engine and supporting functionalities were implemented according to the design. Unit tests were developed to ensure the correctness of individual components.

4. **Testing and Benchmarking**: Extensive testing was conducted to validate the system's functionality and performance. Benchmark testing was performed to assess the efficiency of data structures and algorithms used in the matching engine.

5. **Refinement and Optimization**: Based on testing results, optimizations were made to improve the speed and efficiency of the matching engine. Data structures were optimized to handle large volumes of trading data more effectively.

6. **Integration and Deployment**: The components were integrated, and the system was deployed for testing in a live environment. User feedback was collected from peers for further refinement.

7. **Documentation and Release**: Comprehensive documentation was prepared to guide users on system usage and configuration. The system was released to production with regular updates planned to address user feedback and introduce new features.

## Conclusion
The trading matching engine with candlestick graph provides traders with a powerful toolset for analyzing cryptocurrency markets and making informed trading decisions. By leveraging exchange statistics and visualizing trading data, users can gain valuable insights into market trends and dynamics. The iterative development cycle ensured that the system met performance and usability requirements, resulting in a robust and efficient trading platform.

## Examples
<table>
  <tr>
    <td align="center">
      Print exchange stats
    </td>
    <td align="center">
      Make a bid
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="https://imgur.com/PT1HZtS.png" alt="Print exchange stats screenshot" height="20%"/>
    </td>
    <td align="center">
      <img src="https://imgur.com/chUIQ1r.png" alt="Make a bid screenshot" height="40%"/>
    </td>
  </tr>
  <tr>
    <td align="center">
      Plot volume data
    </td>
    <td align="center">
      Plot Price data
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="https://imgur.com/YGnjaZF.png" alt="Plot volume data screenshot" height="20%"/>
      <img src="https://imgur.com/RT1UFM0.png" alt="Plot volume data screenshot" height="20%"/>
    </td>
    <td align="center">
      <img src="https://imgur.com/KfdcPxj.png" alt="Plot Price data screenshot" height="40%"/>
      <img src="https://imgur.com/xYNxIGQ.png" alt="Plot Price data screenshot" height="40%"/>
    </td>
  </tr>
</table>


<!--
<p align="left">
  Print exchange stats
  <img src="https://imgur.com/PT1HZtS.png" alt="DJ app screenshot" height="20%"/>
</p>

<p align="center">
  Make a bid
  <img src="https://imgur.com/chUIQ1r.png" alt="DJ app screenshot" height="20%"/>
</p>

<p align="right">
  Plot volume data
  <img src="https://imgur.com/YGnjaZF.png" alt="DJ app screenshot" height="20%"/>
</p>

<p align="left">
  Plot volume data
  <img src="https://imgur.com/YGnjaZF.png" alt="DJ app screenshot" height="20%"/>
  <img src="https://imgur.com/RT1UFM0.png" alt="DJ app screenshot" height="20%"/>
</p>


<p align="right">
  Plot Price data
  <img src="https://imgur.com/KfdcPxj.png" alt="DJ app screenshot" height="20%"/>
</p>

-->

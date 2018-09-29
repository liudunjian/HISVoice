
# react-native-almo-hisvoice

## Getting started

`$ npm install react-native-almo-hisvoice --save`

### Mostly automatic installation

`$ react-native link react-native-almo-hisvoice`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-almo-hisvoice` and add `RNAlmoHisvoice.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNAlmoHisvoice.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.hisense.ai.hiasst.RNAlmoHisvoicePackage;` to the imports at the top of the file
  - Add `new RNAlmoHisvoicePackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-almo-hisvoice'
  	project(':react-native-almo-hisvoice').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-almo-hisvoice/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-almo-hisvoice')
  	```


## Usage
```javascript
import RNAlmoHisvoice from 'react-native-almo-hisvoice';

// TODO: What to do with the module?
RNAlmoHisvoice;
```
  
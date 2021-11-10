import React from 'react';
import { Dimensions, Image, ScrollView, StyleSheet, Text, View } from 'react-native';
import ButtonMain from '../components/ButtonMain.android';
import TextBody from '../components/TextBody';
import TextTitle from '../components/TextTitle';
import colors from '../constants/colors';

const GameOverScreen = props => {
  return (
    <ScrollView>
      <View style={styles.screen}>
        <TextTitle>The Game is Over!</TextTitle>
        <View style={styles.imageContainer}>
          <Image
            // source={require('../../assets/success.png')}
            source={{
              uri:
                'https://images.squarespace-cdn.com/content/v1/5c09a1565417fc01fb86eaf9/1548092802241-HO16B8LUSSZA1VX4ZEW9/ke17ZwdGBToddI8pDm48kPnHaqX1Q253z26mJp-11Th7gQa3H78H3Y0txjaiv_0fDoOvxcdMmMKkDsyUqMSsMWxHk725yiiHCCLfrh8O1z5QPOohDIaIeljMHgDF5CVlOqpeNLcJ80NK65_fV7S1UQ93lJt6wopCJh7TMDDA2cGQDtuyOIsUBADKzjul-0ytA_BAmoM8KfSaR3f6p1HyQw/Summit%2BMountains%2BPhoto%2Bcopy.jpg?format=2500w'
            }}
            style={styles.image}
            resizeMode='cover'
          />
        </View>
        <View style={styles.resultContainer}>
          <TextBody style={styles.resultText}>
            Your phone needed <Text style={styles.highlight}>{props.roundsNumber}</Text> rounds to
            guess the number <Text style={styles.highlight}>{props.userNumber}</Text>.
          </TextBody>
        </View>
        <ButtonMain onPress={props.onRestart}>NEW GAME</ButtonMain>
      </View>
    </ScrollView>
  );
};

const styles = StyleSheet.create({
  screen: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    paddingVertical: 10
  },
  imageContainer: {
    width: Dimensions.get('window').width * 0.7,
    height: Dimensions.get('window').width * 0.7,
    borderRadius: (Dimensions.get('window').width * 0.7) / 2,
    borderWidth: 3,
    borderColor: 'black',
    overflow: 'hidden',
    marginVertical: Dimensions.get('window').height / 30
  },
  image: {
    width: '100%',
    height: '100%'
  },
  highlight: {
    color: colors.PRIMARY
  },
  resultContainer: {
    width: 300,
    marginVertical: Dimensions.get('window').height / 60
  },
  resultText: {
    textAlign: 'center',
    fontSize: Dimensions.get('window').width > 350 ? 20 : 16
  }
});

export default GameOverScreen;

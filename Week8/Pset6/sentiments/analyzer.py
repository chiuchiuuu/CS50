import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        file_pos = open(positives, 'r')
        file_neg = open(negatives, 'r')
        pos = file_pos.read().splitlines()
        neg = file_neg.read().splitlines()
        self.positives = [x for x in pos if not x.startswith(";")]
        self.negatives = [x for x in neg if not x.startswith(";")]
        file_pos.close()
        file_neg.close()

        self.tokenizer = nltk.tokenize.TweetTokenizer()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        text = text.lower()
        tokens = self.tokenizer.tokenize(text)
        score = 0

        for token in tokens:
            if token in self.positives:
                score += 1
            elif token in self.negatives:
                score -= 1

        if score > 0:
            return 1
        elif score < 0:
            return -1
        else:
            return 0
